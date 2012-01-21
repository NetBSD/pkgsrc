# $NetBSD: Makefile,v 1.1.1.1 2012/01/21 13:38:41 obache Exp $
#

DISTNAME=	cmigemo-default-src-20110227
PKGNAME=	${DISTNAME:S/-default-src-/-1.3e./}
CATEGORIES=	textproc
MASTER_SITES=	http://cmigemo.googlecode.com/files/
EXTRACT_SUFX=	.zip
DISTFILES=	${DEFAULT_DISTFILES} ${JISYOFILE}

MAINTAINER=	goro@venus.dti.ne.jp
HOMEPAGE=	http://www.kaoriya.net/software/cmigemo
COMMENT=	Migemo library implemented in C
LICENSE=	mit

# sync with inputmethod/skk-jisyo-cdb
SKKJISYO_VERS=	201102
JISYOFILE=	SKK-JISYO.L.${SKKJISYO_VERS}.bz2
SITES.${SKKJISYO_FILE}=	${MASTER_SITE_FREEBSD_LOCAL:=matusita/skk-jisyo/}

BUILD_DEPENDS+= nkf>=2.06:../../converters/nkf

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_TOOLS+=	perl gzip gmake
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/cmigemo-default-src

CONFIGURE_ARGS+=	--prefix=${PREFIX}
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

SUBST_CLASSES+=	prefix
SUBST_STAGE.prefix=	post-configure
SUBST_FILES.prefix=	compile/config_default.mk compile/Make_gcc.mak compile/Make_sun.mak doc/README* tools/migemo.vim
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},g'

BUILD_TARGET=	gcc-all
INSTALL_TARGET=	gcc-install

post-extract:
	${MV} ${WRKDIR}/${JISYOFILE:R} ${WRKSRC}/dict/SKK-JISYO.L

# no need to fetch SKK dictionaly file
TOOLS_NOOP+=	curl

.include "../../mk/bsd.pkg.mk"
