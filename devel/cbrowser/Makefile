# $NetBSD: Makefile,v 1.14 2006/10/05 09:32:02 obache Exp $
#

DISTNAME=       cbrowser-0.8
CATEGORIES=     devel tk
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=cbrowser/}

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       http://cbrowser.sourceforge.net/
COMMENT=        Graphical C/C++ source code browsing tool, and call graph viewer

DEPENDS+=	cscope-[0-9]*:../../devel/cscope
DEPENDS+=	tk-[0-9]*:../../x11/tk

NO_BUILD=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cbrowser ${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${PREFIX}/share/cbrowser
	for f in *.tcl tclIndex; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${PREFIX}/share/cbrowser; \
	done

.include "../../mk/bsd.pkg.mk"
