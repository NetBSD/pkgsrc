# $NetBSD: Makefile,v 1.17 2012/10/31 11:16:44 asau Exp $
#

DISTNAME=	cbrowser-0.8
PKGREVISION=	1
CATEGORIES=	devel tk
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cbrowser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cbrowser.sourceforge.net/
COMMENT=	Graphical C/C++ source code browsing tool, and call graph viewer

DEPENDS+=	cscope-[0-9]*:../../devel/cscope
DEPENDS+=	tk-[0-9]*:../../x11/tk

NO_BUILD=	yes

INSTALLATION_DIRS=	bin share/cbrowser

REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	/usr/local/bin/wish
REPLACE.wish.new=	${LOCALBASE}/bin/wish
REPLACE_FILES.wish=	ftcllib.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cbrowser ${DESTDIR}${PREFIX}/bin
	for f in *.tcl tclIndex; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/share/cbrowser; \
	done

.include "../../mk/bsd.pkg.mk"
