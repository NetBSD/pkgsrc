# $NetBSD: Makefile,v 1.41 2016/01/26 09:01:28 dbj Exp $

DISTNAME=	glimpse-4.18.6
CATEGORIES=	textproc databases
MASTER_SITES=	http://webglimpse.net/trial/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webglimpse.net/
COMMENT=	Text search engine
LICENSE=	isc

# both install bin/agrep (approx. grep)
CONFLICTS+=	tre>=0.7.5nb6

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gmake lex
GNU_CONFIGURE=	yes
MAKE_FLAGS=	mandir=${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS=	share/doc/glimpse

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/glimpse

.include "../../mk/bsd.pkg.mk"
