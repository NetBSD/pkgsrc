# $NetBSD: Makefile,v 1.9 2010/02/10 19:17:40 joerg Exp $
#

DISTNAME=		pymsgauth-2.1.0
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/pymsgauth/
COMMENT=		Automatically process qsecretary confirmation requests

PKG_DESTDIR_SUPPORT=	user-destdir

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

FILES_SUBST+=		SHAREDIR=${SHAREDIR:Q}

INSTALLATION_DIRS=	${SHAREDIR} ${DOCDIR} ${HTMLDOCDIR} ${EGDIR} bin

do-install:
	for f in ${PYTHON_PATCH_SCRIPTS}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$${f} ${DESTDIR}${PREFIX}/${SHAREDIR}; \
	done

	for f in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DESTDIR}${PREFIX}/${DOCDIR}; \
	done

	for f in ${HTMLDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DESTDIR}${PREFIX}/${HTMLDOCDIR}; \
	done

	for f in ${EXAMPLES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DESTDIR}${PREFIX}/${EGDIR}; \
	done

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
