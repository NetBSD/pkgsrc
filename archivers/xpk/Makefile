# $NetBSD: Makefile,v 1.16 2014/10/09 14:05:55 wiz Exp $

DISTNAME=	xpk-0.1.4
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://vesuri.jormas.com/xpk/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jormas.com/~vesuri/xpk/
COMMENT=	The eXternal PacKer (XPK) library system

REPLACE_SH=		xpk-config.in

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
