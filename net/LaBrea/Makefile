# $NetBSD: Makefile,v 1.10 2004/01/20 12:22:18 agc Exp $
#

DISTNAME=	LaBrea2_3
PKGNAME=	LaBrea-2.3
CATEGORIES=	net security
MASTER_SITES=	http://www.hackbusters.net/LaBrea/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.hackbusters.net/LaBrea/
COMMENT=	Builds tarpits/honeypots for scanners

WRKSRC=		${WRKDIR}/LaBrea
USE_BUILDLINK2=	YES

post-extract:
	cd ${WRKSRC};							\
		${MV} LaBrea.c LaBrea.c.in &&				\
		${SED} -e 's/.$$//' -e 's|LaBrea.README|${PREFIX}/share/doc/LaBrea|g' LaBrea.c.in > LaBrea.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/LaBrea ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/LaBrea.README ${PREFIX}/share/doc/LaBrea

.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
