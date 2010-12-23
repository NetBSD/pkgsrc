# $NetBSD: Makefile,v 1.65 2010/12/23 11:44:47 dsainty Exp $

DISTNAME=	xpaint-2.7.8.1
PKGREVISION=	5
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sf-xpaint/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://sf-xpaint.sourceforge.net/
COMMENT=	Simple paint program

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes
USE_TOOLS+=		gmake
MAKE_ENV+=		XMKMF=${XMKMF:Q}
MAKE_JOBS_SAFE=		NO

SUBST_CLASSES+=		foo
SUBST_STAGE.foo=	pre-configure
SUBST_FILES.foo=	Local.config configure
SUBST_SED.foo=		-e "s|@LOCALBASE@|${LOCALBASE}|g" \
			-e "s|@PREFIX@|${PREFIX}|g" \
			-e "s|@XAWDIR@|${BUILDLINK_PREFIX.Xaw3d}|g" \
			-e "s|@XPMDIR@|${BUILDLINK_PREFIX.libXpm}|g"

pre-configure:
	cd ${WRKSRC} && ./configure xaw3dg

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/Xaw3d/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
