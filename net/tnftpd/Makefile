# $NetBSD: Makefile,v 1.3 2003/12/10 02:57:51 lukem Exp $
#

DISTNAME=		tnftpd-20031210
PKGNAME=		tnftpd-20031210
SVR4_PKGNAME=		tnftpd
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/tnftp/

MAINTAINER=		lukem@NetBSD.org
COMMENT=		The NetBSD FTP Daemon

CONFLICTS=		wu-ftpd-[0-9]*
CONFLICTS+=		kth-krb4-[0-9]*
CONFLICTS=		lukemftpd-[0-9]*

GNU_CONFIGURE=		yes
MANCOMPRESSED_IF_MANZ=	yes

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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/tnftpd ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/src/ftpd.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/src/ftpusers.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/src/ftpd.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
