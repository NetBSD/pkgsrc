# $NetBSD: Makefile,v 1.7 1998/04/22 14:22:47 agc Exp $
# FreeBSD Id: Makefile,v 1.39 1998/01/31 17:49:48 jseger Exp
#

DISTNAME=       ncftp-2.4.3
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=	--disable-readline
MAN1=		ncftp2.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ncftp ${PREFIX}/bin/ncftp2
	${INSTALL_MAN} ${WRKSRC}/ncftp.1 ${PREFIX}/man/man1/ncftp2.1

.include "../../mk/bsd.pkg.mk"
