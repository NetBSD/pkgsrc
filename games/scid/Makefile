# $NetBSD: Makefile,v 1.24 2020/03/20 11:57:44 nia Exp $
#

DISTNAME=		scid-3.6.1
PKGREVISION=		11
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scid/}

MAINTAINER=		luapzz@gmail.com
HOMEPAGE=		http://scid.sourceforge.net/
COMMENT=		Shane's Chess Information Database

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

# Make the LINK command CXX and the LDFLAGS.
LINK=			${CXX} ${LDFLAGS}

CONFIGURE_ENV+=		TCLCONFIG_SH=${TCLCONFIG_SH:Q}
CONFIGURE_ARGS+=	BINDIR=${PREFIX}/bin SHAREDIR=${PREFIX}/share/scid
CONFIGURE_ARGS+=	COMPILE=${CXX:Q} OPTIMIZE=${CFLAGS:Q} LINK=${LINK:Q}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing paths to tcl.h and tk.h.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	configure
SUBST_SED.paths=	-e 's,@TCLPREFIX@,${BUILDLINK_PREFIX.tcl},g'
SUBST_SED.paths+=	-e 's,@TKPREFIX@,${BUILDLINK_PREFIX.tk},g'
SUBST_SED.paths+=	-e 's,@LIBDL@,${BUILDLINK_LDADD.dl},g'

MAKE_ENV+=		X_LDFLAGS=${X11_LDFLAGS:Q}

REPLACE_PYTHON+=	scripts/pgnfix.py

.include "../../lang/python/application.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
