# $NetBSD: Makefile,v 1.2 2001/11/07 16:31:26 agc Exp $
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
	${BSD_INSTALL_PROGRAM} ${WRKSRC}/LaBrea ${PREFIX}/sbin
	${BSD_INSTALL_DATA} ${WRKSRC}/LaBrea.README ${PREFIX}/share/doc/LaBrea

.include "../../devel/libnet/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
