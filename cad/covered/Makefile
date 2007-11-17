# $NetBSD: Makefile,v 1.12 2007/11/17 12:04:11 rillig Exp $
#

DISTNAME=	covered-0.4.7
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=covered/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://covered.sourceforge.net/
COMMENT=	Verilog code coverage analyzer (stable release version)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	verilog{,-current}-[0-9]*:../../cad/verilog

CONFLICTS+=	covered-current-[0-9]*

GNU_CONFIGURE=	YES
USE_TOOLS+=	bison gmake lex

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
