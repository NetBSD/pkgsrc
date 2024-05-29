# $NetBSD: Makefile,v 1.21 2024/05/29 16:31:59 adam Exp $
#

PKGVER=		0.8.8
DISTNAME=	compiz-bcop-${PKGVER}
PKGREVISION=	10
CATEGORIES=	devel wm x11
MASTER_SITES=	https://gitlab.com/compiz/compiz-bcop/-/archive/v${PKGVER}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/compiz
COMMENT=	Option code generator for compiz
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool pkg-config msgfmt bash:run
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	bcop.pc.in
DEPENDS+=		getopt-[0-9]*:../../misc/getopt
REPLACE_BASH+=		src/bcop.in

SUBST_CLASSES+=		getopt
SUBST_STAGE.getopt=	pre-configure
SUBST_FILES.getopt=	src/bcop.in
SUBST_SED.getopt=	-e "s|getopt|${PREFIX}/bin/getopt|"

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
