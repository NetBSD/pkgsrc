# $NetBSD: Makefile,v 1.23 2014/01/11 14:42:01 adam Exp $
#

DISTNAME=	covered-${SNAPDATE}
PKGNAME=	covered-current-${SNAPDATE}
PKGREVISION=	5
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=covered/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://covered.sourceforge.net/
COMMENT=	Verilog code coverage analyzer (development snapshot)

PKG_INSTALLATION_TYPES= overwrite pkgviews

DEPENDS+=	verilog{,-current}-[0-9]*:../../cad/verilog

CONFLICTS+=	covered-[0-9]*

SNAPDATE=	20060904
GNU_CONFIGURE=	YES
USE_TOOLS+=	bison gmake lex

REPLACE_INTERPRETER+=	WISH
REPLACE.WISH.old=	.*wish
REPLACE.WISH.new=	${PREFIX}/bin/wish
REPLACE_FILES.WISH=	scripts/main_view.tcl
REPLACE_FILES.WISH+=	scripts/menu_create.tcl
REPLACE_FILES.WISH+=	scripts/preferences.tcl
REPLACE_FILES.WISH+=	scripts/summary.tcl

# we use this hack of setting a cache variable because
# the configure script uses AC_PATH_PROG to try and find
# the *Config.sh scripts but these are not installed with
# the execute bit set.
CONFIGURE_ENV+=	r_cv_path_TCL_CONFIG=${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh
CONFIGURE_ENV+=	r_cv_path_TK_CONFIG=${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh

.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
