# $NetBSD: Makefile,v 1.33 2004/04/25 08:07:46 snj Exp $
# FreeBSD Id: Makefile,v 1.39 1998/01/31 17:49:48 jseger Exp
#

DISTNAME=		ncftp-2.4.3
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ncftp.com/ncftp/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ncftp.com/ncftp/
COMMENT=		FTP replacement with advanced user interface

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-extra-dirs
CONFIGURE_ARGS+=	--disable-ncurses
CONFIGURE_ENV+=		ac_cv_lib_intl_strftime=no

.include "../../mk/bsd.prefs.mk"

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
BUILD_DEFS+=		USE_SOCKS
.  if ${USE_SOCKS} == 4
CONFIGURE_ARGS+= 	--enable-socks
.    include "../../net/socks4/buildlink3.mk"
.  else
CONFIGURE_ARGS+= 	--enable-socks5
.    include "../../net/socks5/buildlink3.mk"
.  endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ncftp ${PREFIX}/bin/ncftp2
	${INSTALL_MAN} ${WRKSRC}/ncftp.1 ${PREFIX}/man/man1/ncftp2.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
