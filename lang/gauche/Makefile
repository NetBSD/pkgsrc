# $NetBSD: Makefile,v 1.44 2008/02/25 23:14:19 tnn Exp $
#

DISTNAME=	Gauche-0.8.13
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gauche/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	uebayasi@NetBSD.org, minoura@NetBSD.org
HOMEPAGE=	http://www.shiro.dreamhost.com/scheme/gauche/index.html
COMMENT=	R5RS Scheme implementation aimed to be a handy tool for daily works

DEPENDS+=	slib-[0-9]*:../../devel/slib

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

EVAL_PREFIX+=		SLIB_PREFIX=slib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-slib=${SLIB_PREFIX}/share/slib
CONFIGURE_ARGS+=	--enable-threads=pthreads
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
.include "../../converters/libiconv/buildlink3.mk"
.if defined(BUILDLINK_LDADD.iconv) && !empty(BUILDLINK_LDADD.iconv:M-l*)
CONFIGURE_ARGS+=	--with-iconv-lib=${BUILDLINK_LDADD.iconv:M-l*:S/-l//:Q}
MAKE_ENV+=		ICONV_LDFLAGS=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.iconv}/lib
.endif
MAKE_JOBS_SAFE=	no

USE_LIBTOOL=	yes
USE_TOOLS+=	gzip makeinfo
TEST_TARGET=	check
INFO_FILES=	yes	# PLIST

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-install:
	gzip -d ${DESTDIR}${PREFIX}/${PKGINFODIR}/gauche-ref*gz

.include "../../mk/bsd.pkg.mk"
