# $NetBSD: Makefile,v 1.66 2022/06/30 11:18:35 nia Exp $

DISTNAME=	tmda-1.1.12
PKGREVISION=	8
CATEGORIES=	mail python
MASTER_SITES=	http://tmda.sourceforge.net/ftp/releases/
#MASTER_SITES+=	ftp://tmda.net/pub/tmda/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://tmda.sourceforge.net/
COMMENT=	Python-based SPAM reduction system

REPLACE_PYTHON=	${TMDA_PROGRAMS}
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.1.12

PKG_SYSCONFSUBDIR=	${PKGBASE}

PKG_GROUPS=		tofmipd
PKG_USERS=		tofmipd:tofmipd
PKG_GECOS.tofmipd=	TMDA ofmipd User

RCD_SCRIPTS=	tofmipd
FILES_SUBST+=	PYTHONBIN=${PYTHONBIN:Q}

SHAREDIR=	share/${PKGBASE}
DOCDIR=		share/doc/${PKGBASE}
EGDIR=		share/examples/${PKGBASE}
HTMLDIR=	share/doc/html/${PKGBASE}
PLIST_SUBST+=	SHAREDIR=${SHAREDIR:Q}
PLIST_SUBST+=	DOCDIR=${DOCDIR:Q}
PLIST_SUBST+=	EGDIR=${EGDIR:Q}
PLIST_SUBST+=	HTMLDIR=${HTMLDIR:Q}

TMDA_PROGRAMS=	bin/tmda-*
TMDA_DOCS=	CODENAMES COPYING CRYPTO ChangeLog INSTALL
TMDA_DOCS+=	NEWS README THANKS UPGRADE
TMDA_CONTRIB=	contrib/*

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	do-configure
SUBST_FILES.etc=	bin/tmda-ofmipd TMDA/Auth.py TMDA/Defaults.py
SUBST_SED.etc=		-e 's|/etc|${PKG_SYSCONFDIR}|g'

INSTALLATION_DIRS=	bin ${SHAREDIR} ${DOCDIR} ${HTMLDIR} ${EGDIR}
INSTALLATION_DIRS+=	${PYSITELIB}/TMDA/pythonlib/email/mime
INSTALLATION_DIRS+=	${PYSITELIB}/TMDA/Queue

.include "options.mk"

post-extract:
	rm ${WRKSRC}/doc/html/error.log

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} ./compileall

pre-install:
	find ${WRKSRC} -name "*.orig" -print | xargs rm -f

do-install:
	for f in ${TMDA_PROGRAMS}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$${f} ${DESTDIR}${PREFIX}/bin; \
	done

	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/*.py* ${DESTDIR}${PREFIX}/${PYSITELIB}/TMDA

	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/pythonlib/email/*.py* \
		${DESTDIR}${PREFIX}/${PYSITELIB}/TMDA/pythonlib/email
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/pythonlib/email/mime/*.py* \
		${DESTDIR}${PREFIX}/${PYSITELIB}/TMDA/pythonlib/email/mime
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/Queue/*.py* \
		${DESTDIR}${PREFIX}/${PYSITELIB}/TMDA/Queue

	${INSTALL_DATA} ${WRKSRC}/templates/*.txt ${DESTDIR}${PREFIX}/${SHAREDIR}

	for f in ${TMDA_DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DESTDIR}${PREFIX}/${DOCDIR}; \
	done

	for f in ${TMDA_CONTRIB}; do \
		if [ -f $${f} ]; then \
			${INSTALL_DATA} ${WRKSRC}/$${f} \
				${DESTDIR}${PREFIX}/${EGDIR}; \
		else \
			cp -Rp ${WRKSRC}/$${f} ${DESTDIR}${PREFIX}/${EGDIR}; \
		fi; \
	done

	cp -Rp ${WRKSRC}/doc/html/* ${DESTDIR}${PREFIX}/${HTMLDIR}

post-install:
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/${PYSITELIB}/TMDA \
		${DESTDIR}${PREFIX}/${PYSITELIB}/TMDA/Queue \
		${DESTDIR}${PREFIX}/${PYSITELIB}/TMDA/pythonlib/email \
		${DESTDIR}${PREFIX}/${PYSITELIB}/TMDA/pythonlib/email/mime

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
