# $NetBSD: Makefile,v 1.2 2008/03/03 17:45:38 jlam Exp $
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdelta3 ${DESTDIR}${PREFIX}/bin/xdelta3

.include "../../mk/bsd.pkg.mk"
