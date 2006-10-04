# $NetBSD: Makefile,v 1.12 2006/10/04 21:46:14 wiz Exp $

DISTNAME=	tcl-itcl-20040920
PKGNAME=	${DISTNAME:S/itcl/itcl-current/}
PKGREVISION=	4
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

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
