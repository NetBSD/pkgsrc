# $NetBSD: Makefile,v 1.5 2003/07/21 16:43:16 martti Exp $
#

DISTNAME=       cbrowser-0.6
CATEGORIES=     devel tk80
MASTER_SITES=   http://www.ziplink.net/~felaco/cbrowser/

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=       http://www.ziplink.net/~felaco/cbrowser/
COMMENT=        Graphical C/C++ source code browsing tool, and call graph viewer

DEPENDS+=	cscope-[0-9]*:../../devel/cscope

USE_BUILDLINK2=	# defined
NO_BUILD=	# defined

post-patch:
	${MV} ${WRKSRC}/cbrowser ${WRKSRC}/cbrowser.input && \
		${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/cbrowser.input > ${WRKSRC}/cbrowser

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cbrowser ${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${PREFIX}/share/cbrowser
	for f in builder.tcl calltree.tcl hierarchy.tcl widget.tcl tclIndex; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${PREFIX}/share/cbrowser; \
	done

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
