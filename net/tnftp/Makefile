# $NetBSD: Makefile,v 1.12 2005/05/11 10:00:57 lukem Exp $
#

DISTNAME=		tnftp-20050511
SVR4_PKGNAME=		tnftp
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

# distfile obtained from: ftp://ftp.NetBSD.org/pub/NetBSD/misc/tnftp

MAINTAINER=		lukem@NetBSD.org
COMMENT=		The enhanced FTP client in NetBSD

GNU_CONFIGURE=		YES

CONFLICTS+=		kth-krb4-[0-9]*
CONFLICTS+=		lukemftp-[0-9]*

NO_CHECKSUM=		# defined

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

OPSYSVARS+=		MAKE_ENV
MAKE_ENV.SunOS+=	CPPFLAGS=""

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
