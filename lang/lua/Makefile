# $NetBSD: Makefile,v 1.27 2005/09/07 02:13:19 reed Exp $

DISTNAME=	lua-5.0.2
PKGREVISION=	4
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

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.lua.org/
COMMENT=	Powerful light-weight language for extending applications

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=	yes
DL_AUTO_VARS=	yes
LIBS+=		${BUILDLINK_LDADD.dl}
LUA_CFLAGS=	${CFLAGS}
LUA_LDFLAGS=	${LDFLAGS} ${LIBS}
MAKE_ENV+=	MYCFLAGS=${LUA_CFLAGS:Q} MYLDFLAGS=${LUA_LDFLAGS:Q}

DOCDIR=		${PREFIX}/share/doc/lua
EGDIR=		${PREFIX}/share/examples/lua

.include "../../mk/dlopen.buildlink3.mk"

post-build:
	cd ${WRKSRC}/etc && ${SETENV} ${MAKE_ENV} ${MAKE} bin2c

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; for f in README COPYRIGHT HISTORY; do		\
		${INSTALL_DATA} $$f ${DOCDIR};				\
	done
	cd ${WRKSRC}/doc; for f in *.html *.gif; do			\
		${INSTALL_DATA} $$f ${DOCDIR};				\
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/test; for f in README *.lua; do			\
		${INSTALL_DATA} $$f ${EGDIR};				\
	done
	${INSTALL_DATA_DIR} ${EGDIR}/etc
	cd ${WRKSRC}/etc; for f in README *.c *.h *.lua lua.magic lua.xpm; do \
		${INSTALL_DATA} $$f ${EGDIR}/etc;			\
	done
	${INSTALL_PROGRAM} ${WRKSRC}/etc/bin2c ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
