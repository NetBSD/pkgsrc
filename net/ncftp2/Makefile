# $NetBSD: Makefile,v 1.14 1999/07/06 08:06:48 jlam Exp $
# FreeBSD Id: Makefile,v 1.39 1998/01/31 17:49:48 jseger Exp
#

DISTNAME=       ncftp-2.4.3
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ncftp.com/ncftp/

GNU_CONFIGURE=  yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	ncurses-4.2:../../devel/ncurses
.endif
DEPENDS+=	readline-2.2:../../devel/readline

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
.if ${USE_SOCKS} == 4
CONFIGURE_ARGS+= 	--enable-socks
DEPENDS+=		socks4-2.2:../../net/socks4
.else
CONFIGURE_ARGS+= 	--enable-socks5
DEPENDS+=		socks5-1.0.2:../../net/socks5
.endif
.endif
CPPFLAGS+=		-I${PREFIX}/include
LDFLAGS+=		-L${PREFIX}/lib
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ncftp ${PREFIX}/bin/ncftp2
	${INSTALL_MAN} ${WRKSRC}/ncftp.1 ${PREFIX}/man/man1/ncftp2.1

.include "../../mk/bsd.pkg.mk"
