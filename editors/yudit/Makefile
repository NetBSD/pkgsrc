# $NetBSD: Makefile,v 1.25 2011/02/28 14:52:48 wiz Exp $

DISTNAME=	yudit-2.8.1
CATEGORIES=	editors
MASTER_SITES=	http://yudit.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yudit.org/
COMMENT=	Unicode Text Editor

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake msgmerge
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-x

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
