# $NetBSD: Makefile,v 1.7 2001/05/01 22:40:43 jtb Exp $

DISTNAME=		yplot-1.0.3
CATEGORIES=		graphics math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yplot/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://yplot.sourceforge.net/
COMMENT=		Yorick interface to PLplot

DEPENDS+=		yorick>=1.4:../../math/yorick
DEPENDS+=		plplot>=5.0.3:../../graphics/plplot

PLPLOT_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		PLPLOT_PREFIX=plplot

MAKEFILE=		Makefile.build

# This looks bad, but the build process won't be able to find the PLplot
# include files otherwise.
pre-build:
	${MKDIR} ${WRKSRC}/plplot
	${CP} ${PLPLOT_PREFIX}/include/plplot/*.h ${WRKSRC}/plplot

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yplot ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/yplotl ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} yplot.i yplotl.i yplot_body.i	\
		${PREFIX}/share/yorick/1.4/startup/
	${INSTALL_DATA} ${WRKSRC}/doc/yplot.doc				\
	${PREFIX}/share/yorick/1.4/doc/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/yplot
	${INSTALL_DATA} ${WRKSRC}/doc/ytut.ps ${PREFIX}/share/doc/yplot
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/yplot
	${INSTALL_DATA} ${WRKSRC}/doc/*.i ${PREFIX}/share/examples/yplot/

.include "../../mk/bsd.pkg.mk"
