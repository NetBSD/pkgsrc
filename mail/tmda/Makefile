# $NetBSD: Makefile,v 1.25 2005/06/16 06:58:08 jlam Exp $
#

DISTNAME=	tmda-1.0.3
PKGREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	http://tmda.net/releases/stable/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://tmda.net/
COMMENT=	Python-based SPAM reduction system

USE_PKGINSTALL=		yes
PY_PATCHPLIST=		# defined
PYTHON_PATCH_SCRIPTS=	${TMDA_PROGRAMS}

PKG_SYSCONFSUBDIR=	${PKGBASE}

PYTHON_VERSIONS_ACCEPTED=	24 23 22

PKG_GROUPS=	tofmipd
PKG_USERS=	tofmipd:tofmipd::TMDA\\ ofmipd\\ User

RCD_SCRIPTS=	tofmipd
FILES_SUBST+=	PYTHONBIN=${PYTHONBIN}

SHAREDIR=	share/${PKGBASE}
DOCDIR=		share/doc/${PKGBASE}
CONTRIBDIR=	share/doc/${PKGBASE}/contrib
HTMLDIR=	share/doc/html/${PKGBASE}
PLIST_SUBST+=	SHAREDIR="${SHAREDIR}"
PLIST_SUBST+=	DOCDIR="${DOCDIR}"
PLIST_SUBST+=	CONTRIBDIR="${CONTRIBDIR}"
PLIST_SUBST+=	HTMLDIR="${HTMLDIR}"

TMDA_PROGRAMS=	bin/tmda-*
TMDA_DOCS=	CODENAMES COPYING CRYPTO ChangeLog INSTALL README THANKS UPGRADE
TMDA_HTDOCS=	htdocs/*.html
TMDA_CONTRIB=	contrib/*

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	do-configure
SUBST_FILES.etc=	bin/tmda-ofmipd TMDA/Auth.py TMDA/Defaults.py
SUBST_SED.etc=		-e 's|/etc|${PKG_SYSCONFDIR}|g'

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} ./compileall

do-install:
	for f in ${TMDA_PROGRAMS}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$${f} ${PREFIX}/bin; \
	done

	${INSTALL_SCRIPT_DIR} ${PREFIX}/${PYSITELIB}/TMDA
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/*.py* ${PREFIX}/${PYSITELIB}/TMDA

	${INSTALL_SCRIPT_DIR} ${PREFIX}/${PYSITELIB}/TMDA/pythonlib/email
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/pythonlib/email/*.py* \
		${PREFIX}/${PYSITELIB}/TMDA/pythonlib/email

	${INSTALL_DATA_DIR} ${PREFIX}/${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/templates/*.txt ${PREFIX}/${SHAREDIR}

	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	for f in ${TMDA_DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${PREFIX}/${DOCDIR}; \
	done

	${INSTALL_DATA_DIR} ${PREFIX}/${CONTRIBDIR}
	for f in ${TMDA_CONTRIB}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${PREFIX}/${CONTRIBDIR}; \
	done

	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	for f in ${TMDA_HTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${PREFIX}/${HTMLDIR}; \
	done

	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}/img
	${INSTALL_DATA} ${WRKSRC}/htdocs/img/*.png ${PREFIX}/${HTMLDIR}/img

post-install:
	${PREFIX}/bin/tmda-ofmipd -V >/dev/null 2>&1

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
