# $NetBSD: Makefile,v 1.12 2002/09/02 08:13:54 tron Exp $
#

DISTNAME=		lukemftp-1.6-beta2
PKGNAME=		lukemftp-1.6rc2
SVR4_PKGNAME=		luftp
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.fi.netbsd.org/pub/NetBSD/misc/lukemftp/ \
			ftp://ftp.netbsd.org/pub/NetBSD/misc/lukemftp/

MAINTAINER=		lukem@netbsd.org
COMMENT=		the enhanced ftp client in NetBSD

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
.if ${USE_SOCKS} == 4
DEPENDS+=		socks4-2.2:../../net/socks4
CONFIGURE_ARGS+=	--with-socks4
.else
DEPENDS+=		socks5-1.0.2:../../net/socks5
CONFIGURE_ARGS+=	--with-socks5
.endif
.endif

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=""
.endif

.include "../../mk/bsd.pkg.mk"
