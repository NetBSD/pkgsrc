# $NetBSD: Makefile,v 1.18 2005/12/05 20:50:28 rillig Exp $

DISTNAME=	itcl3.2.1_src
PKGNAME=	tcl-itcl-3.2.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=incrtcl/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://incrtcl.sourceforge.net/itcl/
COMMENT=	[incr Tcl] object-oriented extension to Tcl/Tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	tcl-itcl-current-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}/itcl3.2.1
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl:Q}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk:Q}/lib
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=	AR=${AR:Q}

MAKE_ENV+=	TCL_HEADER_DIR=${BUILDLINK_PREFIX.tcl}/include/tcl

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
