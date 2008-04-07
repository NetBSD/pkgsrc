# $NetBSD: Makefile,v 1.3 2008/04/07 18:26:21 joerg Exp $
#

DISTNAME=		xdelta30q
PKGNAME=		xdelta3-3.0q
CATEGORIES=		devel
MASTER_SITES=		http://xdelta.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://code.google.com/p/xdelta/
COMMENT=		Enhanced diff that works on binary files (version 3.x)

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		xdelta3
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdelta3 ${DESTDIR}${PREFIX}/bin/xdelta3

.include "../../mk/bsd.pkg.mk"
