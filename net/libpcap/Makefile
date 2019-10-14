# $NetBSD: Makefile,v 1.65 2019/10/14 20:10:19 triaxx Exp $

DISTNAME=	libpcap-1.9.1
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcpdump.org/
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
