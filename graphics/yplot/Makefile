# $NetBSD: Makefile,v 1.5 2001/04/14 21:43:46 jtb Exp $

DISTNAME=		yplot-1.0.3
CATEGORIES=		graphics math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yplot/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://yplot.sourceforge.net/
COMMENT=		Yorick interface to PLplot

DEPENDS+=		yorick>=1.4:../../math/yorick
DEPENDS+=		plplot>=5.0.3:../../graphics/plplot

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
	@for f in yplot.i yplotl.i yplot_body.i; do			\
	i="${INSTALL_DATA} ${WRKSRC}/$$f				\
	${PREFIX}/share/yorick/1.4/startup/";				\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA} ${WRKSRC}/doc/yplot.doc				\
	${PREFIX}/share/yorick/1.4/doc/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/yplot
	${INSTALL_DATA} ${WRKSRC}/doc/ytut.ps ${PREFIX}/share/doc/yplot
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/yplot
	@for f in ${WRKSRC}/doc/*.i; do					\
	i="${INSTALL_DATA} $$f ${PREFIX}/share/examples/yplot/";	\
	${ECHO} $$i; $$i;						\
	done

.include "../../mk/bsd.pkg.mk"
