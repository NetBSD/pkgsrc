# $NetBSD: Makefile,v 1.2 1999/01/30 23:18:52 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1998/09/25 10:07:44 asami Exp
#

DISTNAME=	abacus-0.9.13
CATEGORIES=	math x11
MASTER_SITES=	http://www-cad.eecs.berkeley.edu/HomePages/aml/abacus/ \
		http://tahoe.inesc.pt/~aml/abacus/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www-cad.eecs.berkeley.edu/HomePages/aml/abacus/abacus.html

DEPENDS+=	tcl-8.0p2:../../lang/tcl80
DEPENDS+=	tk-8.0p2:../../x11/tk80

USE_GMAKE=	yes
USE_X11BASE=	yes

# Until we have tcl 8.0.3 in pkgsrc
pre-build:
	@ ${RM} -f ${WRKSRC}/canvas
	@ ${LN} -fs ${WRKSRC}/canvas-tcl8.0.0 ${WRKSRC}/canvas

do-install:
	@ ${SED} s!@PREFIX@!${PREFIX}!g ${WRKSRC}/abacus >${WRKSRC}/abacus.sh
	@ ${INSTALL_SCRIPT} ${WRKSRC}/abacus.sh ${PREFIX}/bin/abacus
	@ ${MKDIR} ${PREFIX}/share/abacus
	@ ${MKDIR} ${PREFIX}/share/abacus/display
	@ ${INSTALL_DATA} ${WRKSRC}/display/*.tcl ${PREFIX}/share/abacus/display
	@ ${MKDIR} ${PREFIX}/share/abacus/graphics
	@ ${INSTALL_DATA} ${WRKSRC}/graphics/*.tcl ${PREFIX}/share/abacus/graphics
	@ ${MKDIR} ${PREFIX}/share/abacus/runlib
	@ ${INSTALL_DATA} ${WRKSRC}/runlib/*.tcl ${PREFIX}/share/abacus/runlib
	@ ${INSTALL_DATA} ${WRKSRC}/runlib/version ${PREFIX}/share/abacus/runlib
	@ ${MKDIR} ${PREFIX}/share/abacus/runlib/bitmaps
	@ ${INSTALL_DATA} ${WRKSRC}/runlib/bitmaps/* ${PREFIX}/share/abacus/runlib/bitmaps
	@ ${MKDIR} ${PREFIX}/share/abacus/tcl_interf
	@ ${INSTALL_PROGRAM} ${WRKSRC}/tcl_interf/nxlc ${PREFIX}/share/abacus/tcl_interf
	@ ${MKDIR} ${PREFIX}/share/examples/abacus
	@ ${INSTALL_DATA} ${WRKSRC}/regressive/* ${PREFIX}/share/examples/abacus
	@ ${MKDIR} ${PREFIX}/share/doc/abacus
	@ ${INSTALL_DATA} ${WRKSRC}/doc/abacus.ps ${PREFIX}/share/doc/abacus
	@ ${INSTALL_DATA} ${WRKSRC}/doc/abacus.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
