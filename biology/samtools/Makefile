# $NetBSD: Makefile,v 1.16 2022/06/30 11:18:04 nia Exp $

DISTNAME=	samtools-1.15
PKGREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://www.htslib.org/
COMMENT=	Tools for manipulating sequence alignment maps
LICENSE=	mit

USE_TOOLS+=	autoconf automake autoreconf bash gmake perl
GNU_CONFIGURE=	yes

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_SED.version+=	-e "s|m4_esyscmd_s(\[./version.sh 2>/dev/null\])|[${PKGVERSION_NOREV}]|"
SUBST_FILES.version+=	configure.ac

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-configure
SUBST_SED.bash+=	-e "s|'bash'|'${TOOLS_PATH.bash}'|"
SUBST_SED.bash+=	-e 's|\\/bin\\/bash|${TOOLS_PATH.bash:S,/,\\\/,g}|'
SUBST_FILES.bash+=	test/test.pl

REPLACE_PERL+=		misc/*.pl
REPLACE_PERL+=		test/*.pl
REPLACE_PERL+=		misc/plot-bamstats misc/plot-ampliconstats
REPLACE_LUA+=		misc/*.lua

CONFIGURE_ARGS+=	--with-htslib=system
TEST_TARGET=		test

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../biology/htslib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
