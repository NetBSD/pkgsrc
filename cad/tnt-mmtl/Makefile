# $NetBSD: Makefile,v 1.16 2011/01/22 18:25:47 dmcmahill Exp $
#

DISTNAME=	tnt-1.2.2
PKGNAME=	${DISTNAME:S/tnt/tnt-mmtl/}
PKGREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mmtl/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://mmtl.sourceforge.net/
COMMENT=	Multilayer Multiconductor Transmission Line 2-D and 2.5-D simulator

BUILD_DEPENDS+=	latex2html-[0-9]*:../../textproc/latex2html

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_TOOLS+=	autoconf automake gmake
USE_LANGUAGES=	c c++ fortran77
TEX_DEPMOD=	build
TEX_ACCEPTED=	teTeX3

# without this, configure ends up using 'gcc -E' for CPP and
# passing that down via an environment variable to f2c-f77 which 
# in turn ends up feeding a .F file to gcc -E that fails due to 
# fortran not being a configured language.  This is what happens on 
# a stock NetBSD-5.1 install.
CONFIGURE_ENV+=	CPP=${CPP}

post-patch:
	${MV} ${WRKSRC}/tnt ${WRKSRC}/tnt-mmtl
	cd ${WRKSRC}/bem && aclocal
	cd ${WRKSRC}/bem && automake
	cd ${WRKSRC}/bem && autoconf

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-itcl-current/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../x11/tk-BWidget/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
