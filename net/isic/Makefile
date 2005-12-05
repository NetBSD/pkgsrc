# $NetBSD: Makefile,v 1.14 2005/12/05 20:50:46 rillig Exp $
#

DISTNAME=	isic-0.06
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/Projects/ISIC/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.packetfactory.net/Projects/ISIC/
COMMENT=	Ip Stack Integrity Checker (IP, TCP, UDP, ICMP et. al.)

GNU_CONFIGURE=	YES

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
CONFIGURE_ENV+= CPPFLAGS=${CPPFLAGS:M*:Q}
CONFIGURE_ENV+= CFLAGS=${CFLAGS:M*:Q}
.  endif
.endif
