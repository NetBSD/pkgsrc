# $NetBSD: Makefile,v 1.1.1.1 2007/04/23 10:17:42 tnn Exp $
#

DISTNAME=		xdelta30q
PKGNAME=		xdelta3-3.0q
CATEGORIES=		devel
MASTER_SITES=		http://xdelta.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://code.google.com/p/xdelta/
COMMENT=		Enhanced diff that works on binary files (version 3.x)

BUILD_TARGET=		xdelta3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdelta3 ${PREFIX}/bin/xdelta3

.include "../../mk/bsd.pkg.mk"
