# $NetBSD: Makefile,v 1.2 2008/05/14 16:40:20 drochner Exp $
#

DISTNAME=	compiz-bcop-0.6.0
CATEGORIES=	wm x11
MASTER_SITES=	http://releases.compiz-fusion.org/0.6.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.compiz-fusion.org/
COMMENT=	Option code generator for compiz

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
