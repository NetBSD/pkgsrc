# $NetBSD: Makefile,v 1.5 2003/12/19 10:52:18 agc Exp $
#

DISTNAME=		tnftp-20030825
SVR4_PKGNAME=		tnftp
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/tnftp/

MAINTAINER=		lukem@NetBSD.org
COMMENT=		The enhanced FTP client in NetBSD

GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == "4" || ${USE_SOCKS} == "5")
.  if ${USE_SOCKS} == "4"
DEPENDS+=		socks4-2.2:../../net/socks4
CONFIGURE_ARGS+=	--with-socks4
.  else
DEPENDS+=		socks5-1.0.2:../../net/socks5
CONFIGURE_ARGS+=	--with-socks5
.  endif
.endif

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=""
.endif

.include "../../mk/bsd.pkg.mk"
