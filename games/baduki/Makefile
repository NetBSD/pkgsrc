# $NetBSD: Makefile,v 1.39 2008/07/14 12:56:03 joerg Exp $

DISTNAME=	baduki-0.2.9
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	ftp://autoinst.nacs.uci.edu/pub/go/baduki/

MAINTAINER=	bad@NetBSD.org
# HOMEPAGE=	gone since 2000
COMMENT=	Go playing program based on xamigo

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
