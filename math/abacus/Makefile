# $NetBSD: Makefile,v 1.12 2001/05/05 19:51:16 jlam Exp $
# FreeBSD Id: Makefile,v 1.3 1998/09/25 10:07:44 asami Exp
#

DISTNAME=	abacus-0.9.13
CATEGORIES=	math x11
MASTER_SITES=	http://www-cad.eecs.berkeley.edu/HomePages/aml/abacus/ \
		http://tahoe.inesc.pt/~aml/abacus/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www-cad.eecs.berkeley.edu/HomePages/aml/abacus/abacus.html
COMMENT=	Spread sheet for X Window System

DEPENDS+=	tcl>=8.3.2:../../lang/tcl
DEPENDS+=	tk>=8.3.2:../../x11/tk

BROKEN=		This package has been updated to compile with tcl-8.3.2, but dumps core on startup.

USE_GMAKE=	yes
USE_X11BASE=	yes

pre-patch:
	@for d in `${FIND} ${WRKSRC} -name RCS -type d -print`; do	\
		${MV} $$d $$d-dist;					\
	done

# Until we have tcl 8.0.3 in pkgsrc
#pre-build:
#	@ ${RM} -f ${WRKSRC}/canvas
#	@ ${LN} -fs ${WRKSRC}/canvas-tcl8.0.0 ${WRKSRC}/canvas

do-install:
	@ ${SED} s!@PREFIX@!${PREFIX}!g ${WRKSRC}/abacus >${WRKSRC}/abacus.sh
	@ ${INSTALL_SCRIPT} ${WRKSRC}/abacus.sh ${PREFIX}/bin/abacus
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/abacus
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/abacus/display
	@ ${INSTALL_DATA} ${WRKSRC}/display/*.tcl ${PREFIX}/share/abacus/display
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/abacus/graphics
	@ ${INSTALL_DATA} ${WRKSRC}/graphics/*.tcl ${PREFIX}/share/abacus/graphics
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/abacus/runlib
	@ ${INSTALL_DATA} ${WRKSRC}/runlib/*.tcl ${PREFIX}/share/abacus/runlib
	@ ${INSTALL_DATA} ${WRKSRC}/runlib/version ${PREFIX}/share/abacus/runlib
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/abacus/runlib/bitmaps
	@ ${INSTALL_DATA} ${WRKSRC}/runlib/bitmaps/* ${PREFIX}/share/abacus/runlib/bitmaps
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/abacus/tcl_interf
	@ ${INSTALL_PROGRAM} ${WRKSRC}/tcl_interf/nxlc ${PREFIX}/share/abacus/tcl_interf
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/examples/abacus
	@ ${INSTALL_DATA} ${WRKSRC}/regressive/* ${PREFIX}/share/examples/abacus
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/doc/abacus
	@ ${INSTALL_DATA} ${WRKSRC}/doc/abacus.ps ${PREFIX}/share/doc/abacus
	@ ${INSTALL_DATA} ${WRKSRC}/doc/abacus.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
