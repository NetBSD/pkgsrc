# $NetBSD: Makefile,v 1.3 2003/08/05 13:35:47 drochner Exp $
#

DISTNAME=	kopete-0.6.2
PKGREVISION=	1
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kopete/}

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

.include "../../audio/arts/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
