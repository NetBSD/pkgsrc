# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:13 tv Exp $
#

DISTNAME=	tnt-1.2.2
PKGNAME=	${DISTNAME:S/tnt/tnt-mmtl/}
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mmtl/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://mmtl.sourceforge.net/
COMMENT=	Multilayer Multiconductor Transmission Line 2-D and 2.5-D simulator

BUILD_DEPENDS+=	latex2html-*:../../textproc/latex2html
BUILD_DEPENDS+=	teTeX>=1.0.7:../../print/teTeX

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++ fortran
USE_FORTRAN=	YES

post-patch:
	${MV} ${WRKSRC}/tnt ${WRKSRC}/tnt-mmtl

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-itcl-current/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../x11/tk-BWidget/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
