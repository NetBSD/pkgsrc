# $NetBSD: Makefile,v 1.7 2003/06/02 01:18:04 jschauma Exp $
#

DISTNAME=	LaBrea2_3
PKGNAME=	LaBrea-2.3
WRKSRC=		${WRKDIR}/LaBrea
CATEGORIES=	net security
MASTER_SITES=	http://www.hackbusters.net/LaBrea/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.hackbusters.net/LaBrea/
COMMENT=	builds tarpits/honeypots for scanners

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
