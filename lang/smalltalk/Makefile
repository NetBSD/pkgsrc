# $NetBSD: Makefile,v 1.71 2012/10/02 20:11:53 asau Exp $

DISTNAME=	smalltalk-3.2.4
PKGREVISION=	9
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=smalltalk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.smalltalk.org/versions/GNUSmalltalk.html
COMMENT=	GNU Smalltalk: A smalltalk-80 implementation

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-sparc *-*-powerpc

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gawk gmake makeinfo pkg-config zip
USE_GNU_READLINE=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-system-libsigsegv=${BUILDLINK_PREFIX.libsigsegv}/lib
CONFIGURE_ARGS+=	--with-system-libffi=${BUILDLINK_PREFIX.libffi}/lib
CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}/lib
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}/lib
CONFIGURE_ARGS+=	--with-lispdir=${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}/lib
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ARGS+=	--without-emacs
#CONFIGURE_ARGS+=	--without-glib --without-gtk
#CONFIGURE_ENV+=		CFLAGS="-O2 -fsigned-char"
CONFIGURE_ENV+=		ac_cv_header_sqlite3_h=no

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

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

post-extract:
	sed -e "s/long double/double/g" -e "s/1.0L/1.0/g" -e  "s/0.0L/0.0/g" \
	-e "s/LDBL_EPSILON/DBL_EPSILON/g" -e "s/truncl/trunc/g" \
	${WRKSRC:Q}/lib-src/truncl.c > ${WRKSRC:Q}/lib-src/trunc.c
	sed -e "s/long double/float/g" -e "s/1.0L/1.0F/g" -e  "s/0.0L/0.0F/g" \
	-e "s/LDBL_EPSILON/FLT_EPSILON/g" -e "s/truncl/truncf/g" \
	${WRKSRC}/lib-src/truncl.c > ${WRKSRC}/lib-src/truncf.c

.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/libsigsegv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
