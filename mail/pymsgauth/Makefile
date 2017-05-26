# $NetBSD: Makefile,v 1.14 2017/05/26 01:35:58 schmonz Exp $
#

DISTNAME=		pymsgauth-2.1.0
PKGREVISION=		6
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/pymsgauth/
COMMENT=		Automatically process qsecretary confirmation requests
LICENSE=		gnu-gpl-v2

PYMSGAUTH_PROGRAMS=	pymsgauth-*
DOCS=			BUGS CHANGELOG COPYING pymsgauth.txt
HTMLDOCS=		pymsgauth.html
EXAMPLES=		pymsgauthrc-example

SHAREDIR=		share/pymsgauth
DOCDIR=			share/doc/pymsgauth
HTMLDOCDIR=		share/doc/html/pymsgauth
EGDIR=			share/examples/pymsgauth

NO_BUILD=		yes
REPLACE_PYTHON=		${PYMSGAUTH_PROGRAMS} *.py
PYTHON_VERSIONS_ACCEPTED=	27

FILES_SUBST+=		SHAREDIR=${SHAREDIR:Q}

INSTALLATION_DIRS=	${SHAREDIR} ${DOCDIR} ${HTMLDOCDIR} ${EGDIR} bin

do-install:
	for f in ${REPLACE_PYTHON}; do \
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
