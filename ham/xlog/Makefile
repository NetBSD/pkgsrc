# $NetBSD: Makefile,v 1.105 2023/01/29 21:16:52 ryoon Exp $
#

DISTNAME=	xlog-2.0.24
PKGREVISION=	2
CATEGORIES=	ham
MASTER_SITES=	https://download.savannah.gnu.org/releases/xlog/
LICENSE=	gnu-gpl-v3

MAINTAINER=	pkgsrc-users@NetBSD.org
# Beware that the author is opposed to anyone else building from the
# repo, instead of distfiles, and objects to bug reports.
# Beware that the upstream homepage will lead you to the wrong repo.
# https://savannah.nongnu.org/bugs/?60068
HOMEPAGE=	https://www.nongnu.org/xlog/
COMMENT=	Amateur Radio logging program

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

.include "../../mk/compiler.mk"

# Fails with gcc 5.5.0 (netbsd-8), and presumably earlier.
# OK with gcc 7.4.0.
# Fails with clang.
.if !empty(CC_VERSION:Mgcc-[45].*) || !empty(PKGSRC_COMPILER:Mclang)
BUILDLINK_TRANSFORM+=	rm:-Wno-stringop-truncation
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-but-set-variable
# xlog has things like: #pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
# https://savannah.nongnu.org/bugs/index.php?60003
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=unknown-warning-option
CWRAPPERS_APPEND.cc+=	-Wno-error=unknown-warning-option
# xlog has code that triggers clang warnings
# https://savannah.nongnu.org/bugs/index.php?60004
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=parentheses-equality
CWRAPPERS_APPEND.cc+=	-Wno-error=parentheses-equality
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=uninitialized
CWRAPPERS_APPEND.cc+=	-Wno-error=uninitialized
.endif

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
