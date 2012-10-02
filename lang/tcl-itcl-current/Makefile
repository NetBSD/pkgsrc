# $NetBSD: Makefile,v 1.18 2012/10/02 20:11:55 asau Exp $

DISTNAME=	tcl-itcl-20040920
PKGNAME=	${DISTNAME:S/itcl/itcl-current/}
PKGREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
# 3.3RC (2005) on sourceforge

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incrtcl.sourceforge.net/itcl/
COMMENT=	[incr Tcl] object-oriented extension to Tcl/Tk.  CVS snapshot

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	tcl-itcl-[0-9]*

WRKSRC=		${WRKDIR}/tcl-itcl-${ITCL_VERS}
ITCL_VERS=	3.3
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl:Q}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk:Q}/lib
CONFIGURE_ARGS+=	--enable-shared

MAKE_ENV+=	TCL_HEADER_DIR=${BUILDLINK_PREFIX.tcl:Q}/include/tcl

SUBST_CLASSES+=		tcl-itcl
SUBST_STAGE.tcl-itcl=	post-build
SUBST_FILES.tcl-itcl=	itcl/itclConfig.sh
SUBST_SED.tcl-itcl=	-e 's|^\(.*\)='\''\(.*\)'\''|\1="\2"|'
SUBST_SED.tcl-itcl+=	-e s\|${WRKSRC:Q}/itcl\|${PREFIX:Q}/lib/tcl/itcl${ITCL_VERS:Q}\|
SUBST_SED.tcl-itcl+=	-e s\|${PREFIX:Q}/lib/itcl${ITCL_VERS:Q}\|${PREFIX:Q}/lib/tcl/itcl${ITCL_VERS:Q}\|
SUBST_SED.tcl-itcl+=	-e s\|${WRKDIR:Q}/${DISTNAME:C/-src//:Q}\|${PREFIX:Q}\|

INSTALLATION_DIRS+=	lib
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

BUILDLINK_DEPMETHOD.libXt?=	build

# the version of configure in the distfile is from autoconf-2.13 and is not compatible
# with some arguments which are passed down from above.
post-patch:
	cd ${WRKSRC}/iwidgets && autoconf

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
