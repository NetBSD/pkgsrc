# $NetBSD: Makefile,v 1.10 2006/03/04 21:28:54 jlam Exp $

DISTNAME=	xpk-0.1.4
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.jormas.com/~vesuri/xpk/ \
		http://energyhq.homeip.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jormas.com/~vesuri/xpk/
COMMENT=	The eXternal PacKer (XPK) library system

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
