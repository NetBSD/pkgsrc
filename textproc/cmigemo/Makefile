# $NetBSD: Makefile,v 1.13 2019/08/11 13:23:22 wiz Exp $
#

DISTNAME=	cmigemo-default-src-20110227
PKGNAME=	${DISTNAME:S/-default-src-/-1.3e./}
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	http://cmigemo.googlecode.com/files/
EXTRACT_SUFX=	.zip
DISTFILES=	${DEFAULT_DISTFILES} ${JISYOFILE}

MAINTAINER=	goro@venus.dti.ne.jp
HOMEPAGE=	http://www.kaoriya.net/software/cmigemo
COMMENT=	Migemo library implemented in C
LICENSE=	mit

MAKE_JOBS_SAFE=	no

# sync with inputmethod/skk-jisyo-cdb
SKKJISYO_VERS=	201102
JISYOFILE=	SKK-JISYO.L.${SKKJISYO_VERS}.bz2
SITES.${SKKJISYO_FILE}=	${MASTER_SITE_FREEBSD_LOCAL:=matusita/skk-jisyo/}

TOOL_DEPENDS+= nkf>=2.06:../../converters/nkf

HAS_CONFIGURE=	yes
USE_TOOLS+=	perl gzip gmake
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/cmigemo-default-src

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ENV+=		PROGRAM_INSTALL=${INSTALL:Q}
CONFIGURE_ENV+=		PROGRAM_ENCODEFILTER="nkf -x"
CONFIGURE_ENV+=		PROGRAM_HTTP=${TRUE:Q}
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

SUBST_CLASSES+=	prefix
SUBST_STAGE.prefix=	post-configure
SUBST_FILES.prefix=	compile/config_default.mk compile/Make_gcc.mak compile/Make_sun.mak doc/README* tools/migemo.vim
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},g'

BUILD_TARGET=	gcc-all
INSTALL_TARGET=	gcc-install

post-extract:
	${MV} ${WRKDIR}/${JISYOFILE:R} ${WRKSRC}/dict/SKK-JISYO.L

.include "../../mk/bsd.pkg.mk"
