# $NetBSD: Makefile,v 1.73 2026/01/02 08:32:36 adam Exp $

DISTNAME=	libpcap-1.10.6
CATEGORIES=	net
MASTER_SITES=	https://www.tcpdump.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tcpdump.org/
COMMENT=	System-independent interface for user-level packet capture
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex gm4
GNU_CONFIGURE=		yes
CONFIGURE_ARGS.Darwin+=	--disable-universal
PKGCONFIG_OVERRIDE=	libpcap.pc.in

# Versions of SunOS which include getifaddrs confuse the configure script,
# and result in dlpi stubs not being enabled.
CONFIGURE_ARGS.SunOS+=	--with-pcap=dlpi
CONFIGURE_ENV.SunOS+=	ac_cv_func_getifaddrs=no

.include "../../mk/bsd.prefs.mk"

# Requires Availability.h, which debuted with 10.5.
.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 100500
.  include "../../devel/macports-legacy-support/buildlink3.mk"
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/pcap-int.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
