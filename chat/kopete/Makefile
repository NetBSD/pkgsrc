# $NetBSD: Makefile,v 1.8 2003/12/04 19:48:24 xtraeme Exp $
#

DISTNAME=	kopete-0.7.3
PKGREVISION=	1
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kopete/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://kopete.kde.org/
COMMENT=	KDE Instant Messenger

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-tags=CXX
CONFIGURE_ENV+=		ac_cv_have_libpsi="no"

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/lib/libXss.so)
CONFIGURE_ENV+=		ac_cv_lib_Xss_XScreenSaverQueryInfo="no"
.endif

.include "../../audio/arts/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
