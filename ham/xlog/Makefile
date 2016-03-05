# $NetBSD: Makefile,v 1.66 2016/03/05 11:28:42 jperkin Exp $
#

DISTNAME=	xlog-2.0.13
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	http://download.savannah.gnu.org/releases/xlog/
LICENSE=	gnu-gpl-v3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/xlog/
COMMENT=	Amateur Radio logging program

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--enable-hamlib

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-but-set-variable
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=parentheses-equality -Wno-error=tautological-compare
CWRAPPERS_APPEND.cc+=	-Wno-error=parentheses-equality -Wno-error=tautological-compare
.endif

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
