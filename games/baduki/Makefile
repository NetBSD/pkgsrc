# $NetBSD: Makefile,v 1.38 2006/10/04 21:43:00 wiz Exp $

DISTNAME=	baduki-0.2.9
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	ftp://autoinst.nacs.uci.edu/pub/go/baduki/

MAINTAINER=	bad@NetBSD.org
# HOMEPAGE=	gone since 2000
COMMENT=	Go playing program based on xamigo

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
