# $NetBSD: Makefile,v 1.43 2007/11/03 22:36:49 rillig Exp $
#

DISTNAME=	Gauche-0.8.9
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gauche/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	uebayasi@NetBSD.org, minoura@NetBSD.org
HOMEPAGE=	http://www.shiro.dreamhost.com/scheme/gauche/index.html
COMMENT=	R5RS Scheme implementation aimed to be a handy tool for daily works

DEPENDS+=	slib-[0-9]*:../../devel/slib

.include "options.mk"

EVAL_PREFIX+=		SLIB_PREFIX=slib

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=		AS="${CC} -x assembler-with-cpp -c"
CONFIGURE_ARGS+=	--with-slib=${SLIB_PREFIX}/share/slib
CONFIGURE_ARGS+=	--enable-multibyte=utf-8
CONFIGURE_ARGS+=	--enable-threads=pthreads
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-iconv-lib=${BUILDLINK_LDADD.iconv:M-l*:S/-l//:Q}
MAKE_ENV+=	ICONV_LDFLAGS=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.iconv}/lib
MAKE_JOBS_SAFE=	no

USE_TOOLS+=	gzip makeinfo
TEST_TARGET=	check
INFO_FILES=	yes	# PLIST

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-install:
	gzip -d ${PREFIX}/${PKGINFODIR}/gauche-ref*gz

.include "../../mk/bsd.pkg.mk"
