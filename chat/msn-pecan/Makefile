# $NetBSD: Makefile,v 1.10 2011/04/22 13:43:06 obache Exp $
#

DISTNAME=	msn-pecan-0.0.18
PKGREVISION=	7
CATEGORIES=	chat
MASTER_SITES=	http://msn-pecan.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://msn-pecan.googlecode.com/files/
COMMENT=	Alternate MSN protocol plugin for libpurple

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config gmake

.include "../../chat/libpurple/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
