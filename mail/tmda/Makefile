# $NetBSD: Makefile,v 1.14 2003/09/23 01:57:18 kim Exp $
#

DISTNAME=	tmda-0.84
CATEGORIES=	mail python
MASTER_SITES=	http://tmda.net/releases/ \
		http://tmda.net/releases/old/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://tmda.net/
COMMENT=	Python-based SPAM reduction system

PYTHON_VERSIONS_ACCEPTED=	22 21

PY_PATCHPLIST=		# defined
PYTHON_PATCH_SCRIPTS=	${TMDA_PROGRAMS}

SHAREDIR=	share/${PKGBASE}
DOCDIR=		share/doc/${PKGBASE}
CONTRIBDIR=	share/doc/${PKGBASE}/contrib
HTMLDIR=	share/doc/html/${PKGBASE}
PLIST_SUBST+=	SHAREDIR="${SHAREDIR}"
PLIST_SUBST+=	DOCDIR="${DOCDIR}"
PLIST_SUBST+=	CONTRIBDIR="${CONTRIBDIR}"
PLIST_SUBST+=	HTMLDIR="${HTMLDIR}"

TMDA_PROGRAMS=	bin/tmda-address
TMDA_PROGRAMS+=	bin/tmda-check-address
TMDA_PROGRAMS+=	bin/tmda-filter
TMDA_PROGRAMS+=	bin/tmda-inject
TMDA_PROGRAMS+=	bin/tmda-keygen
TMDA_PROGRAMS+=	bin/tmda-ofmipd
TMDA_PROGRAMS+=	bin/tmda-pending
TMDA_PROGRAMS+=	bin/tmda-rfilter
TMDA_PROGRAMS+=	bin/tmda-sendmail

TMDA_DOCS=	CODENAMES
TMDA_DOCS+=	COPYING
TMDA_DOCS+=	CRYPTO
TMDA_DOCS+=	ChangeLog
TMDA_DOCS+=	INSTALL
TMDA_DOCS+=	README
TMDA_DOCS+=	THANKS
TMDA_DOCS+=	UPGRADE

do-build:
	cd ${WRKSRC}; ${PYTHONBIN} ./compileall

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
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${PREFIX}/${CONTRIBDIR}

	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/htdocs/*.html ${PREFIX}/${HTMLDIR}

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
