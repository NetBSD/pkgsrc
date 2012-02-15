# $NetBSD: Makefile,v 1.14 2012/02/15 19:28:18 hans Exp $

DISTNAME=	xpk-0.1.4
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://vesuri.jormas.com/xpk/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jormas.com/~vesuri/xpk/
COMMENT=	The eXternal PacKer (XPK) library system

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_SH=		xpk-config.in

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
