# $NetBSD: Makefile,v 1.96 2021/02/04 21:47:30 gdt Exp $
#

DISTNAME=	xlog-2.0.20
CATEGORIES=	ham
MASTER_SITES=	http://download.savannah.gnu.org/releases/xlog/
LICENSE=	gnu-gpl-v3

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/xlog/
COMMENT=	Amateur Radio logging program

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-but-set-variable
# xlog has things like: #pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
# https://savannah.nongnu.org/bugs/index.php?60003
_WRAP_EXTRA_ARGS.CC+=	-Wno-unknown-warning-option
CWRAPPERS_APPEND.cc+=	-Wno-unknown-warning-option
# xlog has code that triggers clang warnings
# https://savannah.nongnu.org/bugs/index.php?60004
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=parentheses-equality
CWRAPPERS_APPEND.cc+=	-Wno-error=parentheses-equality
_WRAP_EXTRA_ARGS.CC+=	-Wno-uninitialized
CWRAPPERS_APPEND.cc+=	-Wno-uninitialized
.endif

# Fails with gcc 5.5.0 (netbsd-8), and presumably earlier.
# OK with gcc 7.4.0, and OK with at least recent clang.
.if !empty(CC_VERSION:Mgcc-[45].*) 
BUILDLINK_TRANSFORM+=	rm:-Wno-stringop-truncation
.endif

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
