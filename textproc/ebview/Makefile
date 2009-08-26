# $NetBSD: Makefile,v 1.5 2009/08/26 19:58:21 sno Exp $

DISTNAME=		ebview-0.3.6
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ebview/}

MAINTAINER=		yamajun@ofug.net
HOMEPAGE=		http://ebview.sourceforge.net/
COMMENT=		GTK2 based EPWING dictionary browser

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake pkg-config msgfmt
GNU_CONFIGURE=		YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/eb/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
