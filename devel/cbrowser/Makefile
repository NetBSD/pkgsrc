# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:45 jlam Exp $
#

DISTNAME=       cbrowser-0.6
PKGREVISION=	1
CATEGORIES=     devel tk
MASTER_SITES=   http://www.ziplink.net/~felaco/cbrowser/

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=       http://www.ziplink.net/~felaco/cbrowser/
COMMENT=        Graphical C/C++ source code browsing tool, and call graph viewer

DEPENDS+=	cscope-[0-9]*:../../devel/cscope
DEPENDS+=	tk-[0-9]*:../../x11/tk

NO_BUILD=	# defined

INSTALLATION_DIRS=	bin

post-patch:
	${MV} ${WRKSRC}/cbrowser ${WRKSRC}/cbrowser.input && \
		${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/cbrowser.input > ${WRKSRC}/cbrowser

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cbrowser ${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${PREFIX}/share/cbrowser
	for f in builder.tcl calltree.tcl hierarchy.tcl widget.tcl tclIndex; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${PREFIX}/share/cbrowser; \
	done

.include "../../mk/bsd.pkg.mk"
