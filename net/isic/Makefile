# $NetBSD: Makefile,v 1.11 2005/01/20 23:32:50 adrianp Exp $
#

DISTNAME=	isic-0.06
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/Projects/ISIC/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.packetfactory.net/Projects/ISIC/
COMMENT=	Ip Stack Integrity Checker (IP, TCP, UDP, ICMP et. al.)

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
DIST_SUBDIR=	isic

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/isic.README

.include "../../devel/libnet11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# XXX On NetBSD, the egcs and gcc-2.95.3 for:
# XXX
# XXX     alpha
# XXX
# XXX has an optimization bug when compiling with -O2
#
.if ${OPSYS} == "NetBSD"
.  if (${MACHINE_ARCH} == "alpha")
CPPFLAGS:=      ${CPPFLAGS:C/-O[0-9]*//g}
CFLAGS:=        ${CFLAGS:C/-O[0-9]*//g}
CONFIGURE_ENV+= CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+= CFLAGS="${CFLAGS}"
.  endif
.endif
