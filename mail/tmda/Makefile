# $NetBSD: Makefile,v 1.3 2002/04/07 06:56:34 schmonz Exp $
#

DISTNAME=	tmda-0.51
CATEGORIES=	mail python
MASTER_SITES=	http://software.libertine.org/tmda/releases/ \
		http://software.libertine.org/tmda/releases/old/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schmonz@netbsd.org
HOMEPAGE=	http://tmda.sourceforge.net/
COMMENT=	Python-based SPAM reduction system

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
TMDA_PROGRAMS+=	bin/tmda-pending
TMDA_PROGRAMS+=	bin/tmda-rfilter
TMDA_PROGRAMS+=	bin/tmda-sendmail

TMDA_DOCS=	COPYING
TMDA_DOCS+=	CRYPTO
TMDA_DOCS+=	ChangeLog
TMDA_DOCS+=	INSTALL
TMDA_DOCS+=	README
TMDA_DOCS+=	THANKS
TMDA_DOCS+=	UPGRADE

do-build:
	cd ${WRKSRC}; ${PYTHONBIN} ./compileall

do-install:
	for file in ${TMDA_PROGRAMS}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$${file} ${PREFIX}/bin; \
	done

	${INSTALL_SCRIPT_DIR} ${PREFIX}/${PYSITELIB}/TMDA
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/*.py* ${PREFIX}/${PYSITELIB}/TMDA

	${INSTALL_DATA_DIR} ${PREFIX}/${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/templates/*.txt ${PREFIX}/${SHAREDIR}

	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	for file in ${TMDA_DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${file} ${PREFIX}/${DOCDIR}; \
	done

	${INSTALL_DATA_DIR} ${PREFIX}/${CONTRIBDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${PREFIX}/${CONTRIBDIR}

	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/htdocs/*.html ${PREFIX}/${HTMLDIR}

.include "../../lang/python/extension.buildlink.mk"
.include "../../lang/python/application.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
