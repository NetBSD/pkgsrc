# $NetBSD: Makefile,v 1.13 2004/04/05 02:31:06 xtraeme Exp $

DISTNAME=	lua-5.0.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.tecgraf.puc-rio.br/pub/lua/ \
		ftp://ftp.ntua.gr/pub/lang/lua/ \
		ftp://ftp.gwdg.de/pub/languages/lua/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/lua/ \
		ftp://ftp.ucore.com/lua/dist/ \
		ftp://sunsite.dk/pub/languages/lua/ \
		ftp://ftp.chg.ru/pub/lang/lua/ \
		http://www.lua.org/ftp/ \
		http://www.tecgraf.puc-rio.br/lua/ftp/ \
		http://ftp.gwdg.de/pub/languages/lua/ \
		http://mirrors.sunsite.dk/lua/ \
		http://ftp.chg.ru/pub/lang/lua/

MAINTAINER=	pkgsrc@bjan.freeshell.org
HOMEPAGE=	http://www.lua.org/
COMMENT=	Powerful light-weight language for extending applications

USE_BUILDLINK3=	yes
ALL_TARGET=	all so
INSTALL_TARGET=	install soinstall

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/lua
	cd ${WRKSRC}; ${INSTALL_DATA} README COPYRIGHT  \
		HISTORY ${PREFIX}/share/doc/lua
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/lua
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.gif  \
		${PREFIX}/share/doc/html/lua
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/lua
	cd ${WRKSRC}/test && ${INSTALL_DATA} README *.lua \
		${PREFIX}/share/examples/lua
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/lua/etc
	cd ${WRKSRC}/etc && ${INSTALL_DATA} README *.c *.h \
		*.lua lua.magic lua.xpm \
		${PREFIX}/share/examples/lua/etc

.include "../../mk/bsd.pkg.mk"
