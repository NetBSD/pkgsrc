# $NetBSD: Makefile,v 1.31 2006/09/06 14:58:00 abs Exp $

DISTNAME=	lua-5.1.1
PKGREVISION=	1
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

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lua.org/
COMMENT=	Powerful light-weight language for extending applications

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
MAKE_ENV+=	MYCFLAGS=${CFLAGS:M*:Q}
MAKE_ENV+=	MYLDFLAGS=${LDFLAGS:M*:Q}\ ${LIBS:M*:Q}
MAKE_ENV+=	DLLIB=${BUILDLINK_LDADD.dl:Q}

DOCDIR=		${PREFIX}/share/doc/lua
EGDIR=		${PREFIX}/share/examples/lua

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD*)
BUILD_TARGET=	bsd
.elif ${OPSYS} == "Linux"
BUILD_TARGET=	linux
.else
BUILD_TARGET=	generic
.endif

PKGCONFIG_OVERRIDE=	${WRKSRC}/etc/lua.pc

SUBST_CLASSES+=		pc-prefix
SUBST_FILES.pc-prefix+=	${WRKSRC}/etc/lua.pc
SUBST_SED.pc-prefix+=	-e "s,/usr/local,${PREFIX},"
SUBST_STAGE.pc-prefix+=	post-build

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	set -e; \
	cd ${WRKSRC}; for f in README COPYRIGHT HISTORY; do		\
		${INSTALL_DATA} "$$f" ${DOCDIR};			\
	done
	set -e; \
	cd ${WRKSRC}/doc; for f in *.html *.gif; do			\
		${INSTALL_DATA} "$$f" ${DOCDIR};			\
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	set -e; \
	cd ${WRKSRC}/test; for f in README *.lua; do			\
		${INSTALL_DATA} "$$f" ${EGDIR};				\
	done
	${INSTALL_DATA_DIR} ${EGDIR}/etc
	set -e; \
	cd ${WRKSRC}/etc; for f in README *.c *.ico *.lua; do \
		${INSTALL_DATA} "$$f" ${EGDIR}/etc;			\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/etc/lua.pc ${PREFIX}/lib/pkgconfig

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
