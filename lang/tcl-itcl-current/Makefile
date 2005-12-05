# $NetBSD: Makefile,v 1.7 2005/12/05 20:50:28 rillig Exp $

DISTNAME=	tcl-itcl-20040920
PKGNAME=	${DISTNAME:S/itcl/itcl-current/}
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tcltk.com/itcl/
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

MAKE_ENV+=	TCL_HEADER_DIR=${BUILDLINK_PREFIX.tcl}/include/tcl

post-build:
	${SED} -e "s|^\(.*\)='\(.*\)'|\1=\"\2\"|"			\
		-e "s|${WRKSRC}/itcl|${PREFIX}/lib/tcl/itcl${ITCL_VERS}|"\
		-e "s|${PREFIX}/lib/itcl${ITCL_VERS}|${PREFIX}/lib/tcl/itcl${ITCL_VERS}|"\
		-e "s|${WRKDIR}/${DISTNAME:C/-src//}|${PREFIX}|"	\
		${WRKSRC}/itcl/itclConfig.sh > ${WRKSRC}/itcl/itclConfig.sh.tmp &&\
		${MV} ${WRKSRC}/itcl/itclConfig.sh.tmp ${WRKSRC}/itcl/itclConfig.sh

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
