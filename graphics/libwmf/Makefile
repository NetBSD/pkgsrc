# $NetBSD: Makefile,v 1.63 2009/09/02 08:34:13 wiz Exp $

DISTNAME=	libwmf-0.2.8.4
PKGREVISION=	5
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wvware.sourceforge.net/libwmf.html
COMMENT=	Library for reading and converting WMF (Windows Meta Files)

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gd
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/html/libwmf

post-install:
	${RMDIR} ${DESTDIR}${PREFIX}/include/libwmf/gd

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
