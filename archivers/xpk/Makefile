# $NetBSD: Makefile,v 1.8 2005/03/24 21:12:50 wiz Exp $

DISTNAME=	xpk-0.1.4
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.jormas.com/~vesuri/xpk/ \
		http://energyhq.homeip.net/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.jormas.com/~vesuri/xpk/
COMMENT=	The eXternal PacKer (XPK) library system

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_BUILDLINK3=		yes

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
