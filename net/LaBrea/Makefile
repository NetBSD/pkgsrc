# $NetBSD: Makefile,v 1.3 2002/02/06 16:58:15 jlam Exp $
#

DISTNAME=	LaBrea
PKGNAME=	LaBrea-2.0
CATEGORIES=	net security
MASTER_SITES=	http://hts.dshield.org/LaBrea/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://hts.dshield.org/LaBrea/
COMMENT=	builds tarpits/honeypots for scanners

post-extract:
	cd ${WRKSRC};							\
		${MV} LaBrea.c LaBrea.c.in &&				\
		${SED} -e 's/.$$//' -e 's|LaBrea.README|${PREFIX}/share/doc/LaBrea|g' LaBrea.c.in > LaBrea.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/LaBrea ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/LaBrea.README ${PREFIX}/share/doc/LaBrea

.include "../../devel/libnet/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
