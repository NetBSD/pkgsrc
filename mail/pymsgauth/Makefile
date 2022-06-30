# $NetBSD: Makefile,v 1.22 2022/06/30 11:18:35 nia Exp $
#

DISTNAME=		pymsgauth-2.1.0
PKGREVISION=		15
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/pymsgauth/
COMMENT=		Automatically process qsecretary confirmation requests
LICENSE=		gnu-gpl-v2

FILTER3_PATCH+=		pymsgauth-2.1.0-filter3-20180806.patch
PATCHFILES+=		${FILTER3_PATCH}
SITES.${FILTER3_PATCH}=	https://schmonz.com/qmail/pymsgauthfilter/

PYMSGAUTH_PROGRAMS=	pymsgauth-*
DOCS=			BUGS CHANGELOG COPYING pymsgauth.html pymsgauth.txt
EXAMPLES=		pymsgauthrc-example

SHAREDIR=		share/pymsgauth
DOCDIR=			share/doc/pymsgauth
EGDIR=			share/examples/pymsgauth

NO_BUILD=		yes
REPLACE_PYTHON=		${PYMSGAUTH_PROGRAMS} *.py

FILES_SUBST+=		SHAREDIR=${SHAREDIR:Q}

INSTALLATION_DIRS=	${SHAREDIR} ${DOCDIR} ${EGDIR} bin

pre-install:
	cd ${WRKSRC} && ${RM} -f *.orig *.orig_dist

do-install:
	for f in ${REPLACE_PYTHON}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$${f} ${DESTDIR}${PREFIX}/${SHAREDIR}; \
	done

	for f in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DESTDIR}${PREFIX}/${DOCDIR}; \
	done

	for f in ${EXAMPLES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DESTDIR}${PREFIX}/${EGDIR}; \
	done

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
