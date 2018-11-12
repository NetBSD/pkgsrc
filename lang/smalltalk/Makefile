# $NetBSD: Makefile,v 1.105 2018/11/12 03:52:26 ryoon Exp $

DISTNAME=	smalltalk-3.2.5
PKGREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=smalltalk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.smalltalk.org/versions/GNUSmalltalk.html
COMMENT=	GNU Smalltalk: A smalltalk-80 implementation

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-sparc *-*-powerpc

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gawk gmake makeinfo pkg-config zip
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-system-ltdl
CONFIGURE_ARGS+=	--with-system-libsigsegv=${BUILDLINK_PREFIX.libsigsegv}/lib
CONFIGURE_ARGS+=	--with-system-libffi=${BUILDLINK_PREFIX.libffi}/lib
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}/lib
CONFIGURE_ARGS+=	--with-lispdir=${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=	--without-emacs
#CONFIGURE_ENV+=		CFLAGS="-O2 -fsigned-char"

IGNORE_LIBTOOLIZE=	lib/smalltalk/libc.la
INFO_FILES=		YES
TEST_TARGET=		check

REPLACE_PERL=		packages/vfs/deb packages/vfs/mailfs
REPLACE_SED=		examples/pepe.sed examples/xml.sed

REPLACE_INTERPRETER+=	sys-sed
REPLACE.sys-sed.old=	[^[:space:]]*sed
REPLACE.sys-sed.new=	${SED}
REPLACE_FILES.sys-sed=	${REPLACE_SED}

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=	-DUSE_INTERP_RESULT

# for backtrace
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

post-extract:
	sed -e "s/long double/double/g" -e "s/1.0L/1.0/g" -e  "s/0.0L/0.0/g" \
	-e "s/LDBL_EPSILON/DBL_EPSILON/g" -e "s/truncl/trunc/g" \
	${WRKSRC}/lib-src/truncl.c > ${WRKSRC}/lib-src/trunc.c
	sed -e "s/long double/float/g" -e "s/1.0L/1.0F/g" -e  "s/0.0L/0.0F/g" \
	-e "s/LDBL_EPSILON/FLT_EPSILON/g" -e "s/truncl/truncf/g" \
	${WRKSRC}/lib-src/truncl.c > ${WRKSRC}/lib-src/truncf.c

.include "options.mk"


.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/libsigsegv/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
