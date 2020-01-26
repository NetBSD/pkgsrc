# $NetBSD: Makefile,v 1.66 2020/01/26 17:31:50 rillig Exp $

DISTNAME=	libpcap-1.9.1
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tcpdump.org/
COMMENT=	System-independent interface for user-level packet capture
LICENSE=	modified-bsd

NOT_FOR_PLATFORM+=	Interix-*-* # no raw interface access

USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex gm4
GNU_CONFIGURE=		yes
CONFIGURE_ARGS.Darwin+=	--disable-universal
PKGCONFIG_OVERRIDE=	libpcap.pc.in

# Versions of SunOS which include getifaddrs confuse the configure script,
# and result in dlpi stubs not being enabled.
CONFIGURE_ARGS.SunOS+=	--with-pcap=dlpi
CONFIGURE_ENV.SunOS+=	ac_cv_func_getifaddrs=no

post-install:
	${INSTALL_DATA} ${WRKSRC}/pcap-int.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
