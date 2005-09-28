# $NetBSD: Makefile,v 1.2 2005/09/28 20:52:24 rillig Exp $
#

DISTNAME=		pymsgauth-2.1.0
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/pymsgauth/
COMMENT=		Automatically process qsecretary confirmation requests

PYMSGAUTH_PROGRAMS=	pymsgauth-*
DOCS=			BUGS CHANGELOG COPYING pymsgauth.txt
HTMLDOCS=		pymsgauth.html
EXAMPLES=		pymsgauthrc-example

SHAREDIR=		share/pymsgauth
DOCDIR=			share/doc/pymsgauth
HTMLDOCDIR=		share/doc/html/pymsgauth
EGDIR=			share/examples/pymsgauth

NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	${PYMSGAUTH_PROGRAMS} *.py

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=	${PKGDIR}/INSTALL
DEINSTALL_EXTRA_TMPL+=	${PKGDIR}/DEINSTALL
FILES_SUBST+=		SHAREDIR=${SHAREDIR}

INSTALLATION_DIRS=	${SHAREDIR} ${DOCDIR} ${HTMLDOCDIR} ${EGDIR} bin

do-install:
	for f in ${PYTHON_PATCH_SCRIPTS}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$${f} ${PREFIX}/${SHAREDIR}; \
	done

	for f in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${PREFIX}/${DOCDIR}; \
	done

	for f in ${HTMLDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${PREFIX}/${HTMLDOCDIR}; \
	done

	for f in ${EXAMPLES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${PREFIX}/${EGDIR}; \
	done

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
