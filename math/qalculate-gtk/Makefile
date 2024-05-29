# $NetBSD: Makefile,v 1.110 2024/05/29 16:33:28 adam Exp $

DISTNAME=	qalculate-gtk-5.0.0
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=Qalculate/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qalculate.github.io/
COMMENT=	Modern multi-purpose desktop calculator (GTK version)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gdbus-codegen gmake intltool msgfmt msgmerge xgettext pkg-config
GNU_CONFIGURE=		yes

.include "../../math/qalculate/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
