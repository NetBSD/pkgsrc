# $NetBSD: Makefile,v 1.2 2001/11/14 14:47:55 agc Exp $

DISTNAME=	lua-4.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.tecgraf.puc-rio.br/pub/lua/ \
		ftp://csg.uwaterloo.ca/pub/lhf/lua/ \
		ftp://ftp.freesoftware.com/pub/languages/lua/ \
		ftp://ftp.gwdg.de/pub/languages/lua/ \
		ftp://ftp.ntua.gr/pub/lang/lua/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/lua/ \
		ftp://ftp.ucore.com/lua/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.lua.org
COMMENT=	Powerful, light-weight programming language for extending applications

WRKSRC=		${WRKDIR}/lua

post-extract:
	@cd ${WRKSRC}/test; ${RM} -f lua luac

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/lua
	cd ${WRKSRC}; ${INSTALL_DATA} README COPYRIGHT	\
		HISTORY ${PREFIX}/share/doc/lua
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/lua
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.gif  \
		${PREFIX}/share/doc/html/lua
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/lua
	cd ${WRKSRC}/test && ${PAX} -rw . ${PREFIX}/share/examples/lua

.include "../../mk/bsd.pkg.mk"
