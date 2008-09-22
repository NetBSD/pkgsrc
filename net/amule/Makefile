# $NetBSD: Makefile,v 1.37 2008/09/22 20:21:04 joerg Exp $

DISTNAME=	aMule-2.1.3
PKGNAME=	${DISTNAME:S/aMule/amule/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=amule/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tripledes@eslack.org
HOMEPAGE=	http://www.amule.org/
COMMENT=	Another Emule P2P client

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		xmule-[0-9]*

USE_DIRS+=		xdg-1.1
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-wx-config=${LOCALBASE}/bin/wx-config
CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl=yes

LIBS+=			-lm

UNLIMIT_RESOURCES+=	datasize

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/wxGTK26/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
