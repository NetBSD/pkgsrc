# $NetBSD: Makefile,v 1.5 2001/10/18 15:20:30 veego Exp $
#

DISTNAME=		lukemftpd-1.1
SVR4_PKGNAME=		luftd
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/misc/lukemftp/

MAINTAINER=		lukem@netbsd.org
COMMENT=		the enhanced ftp server in NetBSD

CONFLICTS=		wu-ftpd-[0-9]*
CONFLICTS+=		kth-krb4-[0-9]*

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

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=""
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ftpd ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/src/ftpd.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/src/ftpusers.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/src/ftpd.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
