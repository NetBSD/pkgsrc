# $NetBSD: Makefile,v 1.27 2013/01/26 21:37:09 adam Exp $
#

DISTNAME=	msn-pecan-0.0.18
PKGREVISION=	23
CATEGORIES=	chat
MASTER_SITES=	http://msn-pecan.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://msn-pecan.googlecode.com/files/
COMMENT=	Alternate MSN protocol plugin for libpurple

USE_TOOLS+=	pkg-config gmake

.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
