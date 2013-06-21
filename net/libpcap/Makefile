# $NetBSD: Makefile,v 1.56 2013/06/21 13:36:58 jperkin Exp $

DISTNAME=	libpcap-1.4.0
PKGREVISION=	1
SVR4_PKGNAME=	lpcap
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcpdump.org/
COMMENT=	System-independent interface for user-level packet capture
LICENSE=	modified-bsd

NOT_FOR_PLATFORM+=	Interix-*-* # no raw interface access

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex gm4
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--with-pcap=dlpi
# Versions of SunOS which include getifaddrs confuse the configure script,
# and result in dlpi stubs not being enabled.
CONFIGURE_ENV+=		ac_cv_func_getifaddrs=no
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/pcap-int.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
