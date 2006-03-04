# $NetBSD: Makefile,v 1.41 2006/03/04 21:30:21 jlam Exp $

DISTNAME=		ncftp-2.4.3
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ncftp.com/ncftp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ncftp.com/ncftp/
COMMENT=		FTP replacement with advanced user interface

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-extra-dirs
CONFIGURE_ARGS+=	--disable-ncurses
CONFIGURE_ENV+=		ac_cv_lib_intl_strftime=no
CONFIGURE_ENV+=		GZCAT=${GZCAT:Q}
USE_TOOLS+=		gzcat

.include "options.mk"

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ncftp ${PREFIX}/bin/ncftp2
	${INSTALL_MAN} ${WRKSRC}/ncftp.1 ${PREFIX}/man/man1/ncftp2.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
