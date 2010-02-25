# $NetBSD: Makefile,v 1.54 2010/02/25 19:07:53 joerg Exp $
#

DISTNAME=	Gauche-0.9
CATEGORIES=	lang
#PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gauche/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	uebayasi@NetBSD.org, minoura@NetBSD.org
HOMEPAGE=	http://www.shiro.dreamhost.com/scheme/gauche/index.html
COMMENT=	R5RS Scheme implementation aimed to be a handy tool for daily works

DEPENDS+=		slib-[0-9]*:../../devel/slib

PKG_DESTDIR_SUPPORT=	user-destdir
NOT_FOR_BULK_PLATFORM=	HPUX-*-*

.include "options.mk"

EVAL_PREFIX+=		SLIB_PREFIX=slib

MAKE_JOBS_SAFE=		no
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-slib=${SLIB_PREFIX}/share/slib
CONFIGURE_ARGS+=	--enable-threads=pthreads
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}

CHECK_BUILTIN.iconv:=	no
.include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=	yes

.if !empty(USE_BUILTIN.iconv:M[nN][oO])
CONFIGURE_ARGS+=	--with-iconv-lib=${BUILDLINK_LIBNAME.iconv}
ALL_ENV+=		\
	ICONV_LDFLAGS="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.iconv}/lib"
.endif

USE_LIBTOOL=	yes
USE_TOOLS+=	gzip makeinfo
TEST_TARGET=	check
INFO_FILES=	yes

# refer %install in ${WRKSRC}/Gauche.spec
INSTALL_TARGET=	install-pkg install-doc

# Does relink internally
BUILDLINK_PASSTHRU_RPATHDIRS+=	${WRKSRC}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-install:
	gzip -d ${DESTDIR}${PREFIX}/${PKGINFODIR}/gauche-ref*gz

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
