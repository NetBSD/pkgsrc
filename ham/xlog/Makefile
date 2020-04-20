# $NetBSD: Makefile,v 1.89 2020/04/20 22:54:53 mef Exp $
#

DISTNAME=	xlog-2.0.19
CATEGORIES=	ham
MASTER_SITES=	http://download.savannah.gnu.org/releases/xlog/
LICENSE=	gnu-gpl-v3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/xlog/
COMMENT=	Amateur Radio logging program

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-hamlib

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-but-set-variable
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=parentheses-equality -Wno-error=tautological-compare -Wno-unknown-warning-option -Wno-deprecated-declarations
CWRAPPERS_APPEND.cc+=	-Wno-error=parentheses-equality -Wno-error=tautological-compare -Wno-unknown-warning-option -Wno-deprecated-declarations
.endif

# Problematic with 5.5.0 on netbsd-8.
.if !empty(PKGSRC_COMPILER:Mgcc)
BUILDLINK_TRANSFORM+=	rm:-Wno-stringop-truncation
.endif

# Work around https://savannah.nongnu.org/bugs/index.php?57920
_WRAP_EXTRA_ARGS.CC+=	-Wno-deprecated-declarations
CWRAPPERS_APPEND.cc+=	-Wno-deprecated-declarations

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
