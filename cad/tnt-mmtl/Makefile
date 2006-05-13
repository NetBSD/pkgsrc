# $NetBSD: Makefile,v 1.9 2006/05/13 03:44:23 minskim Exp $
#

DISTNAME=	tnt-1.2.2
PKGNAME=	${DISTNAME:S/tnt/tnt-mmtl/}
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mmtl/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://mmtl.sourceforge.net/
COMMENT=	Multilayer Multiconductor Transmission Line 2-D and 2.5-D simulator

BUILD_DEPENDS+=	latex2html-*:../../textproc/latex2html

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++ fortran
TEX_DEPMOD=	build
TEX_ACCEPTED=	teTeX2 teTeX3

post-patch:
	${MV} ${WRKSRC}/tnt ${WRKSRC}/tnt-mmtl

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-itcl-current/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../x11/tk-BWidget/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
