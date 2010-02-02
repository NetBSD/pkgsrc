# $NetBSD: Makefile,v 1.1.1.1 2010/02/02 16:35:46 reed Exp $
#

DISTNAME=	cppcheck-1.40
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppcheck/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://cppcheck.wiki.sourceforge.net/
COMMENT=	Simple syntax checking of C/C++

INSTALLATION_DIRS+=	bin
PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c++

# TODO: manpage is in docbook, needs to be converted

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cppcheck ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
