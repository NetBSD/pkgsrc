# $NetBSD: Makefile,v 1.7 2012/06/14 07:44:43 sbd Exp $
#

PKGVER=		0.8.4
DISTNAME=	compiz-bcop-${PKGVER}
PKGREVISION=	2
CATEGORIES=	devel wm x11
MASTER_SITES=	http://releases.compiz.org/${PKGVER}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.compiz-fusion.org/
COMMENT=	Option code generator for compiz
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool pkg-config msgfmt bash:run
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	bcop.pc.in
DEPENDS+=	getopt-[0-9]*:../../misc/getopt
REPLACE_BASH+=	src/bcop.in

SUBST_CLASSES+=	getopt
SUBST_STAGE.getopt=	pre-configure
SUBST_FILES.getopt=	src/bcop.in
SUBST_SED.getopt=	"s|getopt|${LOCALBASE}/bin/getopt|"

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
