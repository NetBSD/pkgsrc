# $NetBSD: Makefile,v 1.25 2001/05/24 08:53:57 jlam Exp $
# FreeBSD Id: Makefile,v 1.39 1998/01/31 17:49:48 jseger Exp
#

DISTNAME=		ncftp-2.4.3
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ncftp.com/ncftp/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.ncftp.com/ncftp/
COMMENT=		FTP replacement with advanced user interface

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-extra-dirs
CONFIGURE_ARGS+=	--disable-ncurses
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=		ac_cv_lib_intl_strftime=no

.include "../../mk/bsd.prefs.mk"

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
BUILD_DEFS+=		USE_SOCKS
.if ${USE_SOCKS} == 4
CONFIGURE_ARGS+= 	--enable-socks
DEPENDS+=		socks4-2.2:../../net/socks4
.else
CONFIGURE_ARGS+= 	--enable-socks5
DEPENDS+=		socks5-1.0.2:../../net/socks5
.endif
.endif

.include "../../devel/readline/buildlink.mk"

CPPFLAGS+=		-I${BUILDLINK_INCDIR}
LDFLAGS+=		-L${BUILDLINK_LIBDIR}

pre-configure: ${BUILDLINK_TARGETS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ncftp ${PREFIX}/bin/ncftp2
	${INSTALL_MAN} ${WRKSRC}/ncftp.1 ${PREFIX}/man/man1/ncftp2.1

.include "../../mk/bsd.pkg.mk"
