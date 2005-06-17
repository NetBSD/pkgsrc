# $NetBSD: Makefile,v 1.37 2005/06/17 03:50:26 jlam Exp $

DISTNAME=		ncftp-2.4.3
PKGREVISION=	1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ncftp.com/ncftp/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ncftp.com/ncftp/
COMMENT=		FTP replacement with advanced user interface

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

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ncftp ${PREFIX}/bin/ncftp2
	${INSTALL_MAN} ${WRKSRC}/ncftp.1 ${PREFIX}/man/man1/ncftp2.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
