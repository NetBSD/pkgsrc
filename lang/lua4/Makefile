# $NetBSD: Makefile,v 1.1.1.1 2003/04/29 23:15:35 jtb Exp $

DISTNAME=	lua-4.0.1
PKGNAME=	lua4-4.01
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

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.lua.org
COMMENT=	Powerful light-weight language for extending applications

USE_BUILDLINK2=	yes

BUILD_DIRS=	${WRKSRC}/objdir

post-extract:
	${MKDIR} ${BUILD_DIRS}

post-patch:
	${CP} ${WRKSRC}/doc/lua.1 ${BUILD_DIRS}/lua/lua4.1
	${CP} ${WRKSRC}/doc/luac.1 ${BUILD_DIRS}/luac/luac4.1

pre-install:
	for f in ${WRKSRC}/include/*.h; do			\
		${SED} -e 's:lua.h:lua4.h:g' $$f > $$f.tmp	\
		&& ${MV} $$f.tmp $$f;				\
	done

.include "../../mk/bsd.pkg.mk"
