# $NetBSD: Makefile,v 1.7 2002/06/02 00:57:38 schmonz Exp $
#

DISTNAME=		lukemftp-1.5
SVR4_PKGNAME=		luftp
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/misc/lukemftp/

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

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=""
.elseif ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
