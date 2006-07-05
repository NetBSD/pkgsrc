# $NetBSD: Makefile,v 1.34 2006/07/05 05:37:43 jlam Exp $

DISTNAME=	aMule-2.1.1
PKGNAME=	${DISTNAME:S/aMule/amule/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=amule/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tripledes@eslack.org
HOMEPAGE=	http://www.amule.org/
COMMENT=	Another Emule P2P client

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
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
