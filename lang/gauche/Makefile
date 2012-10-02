# $NetBSD: Makefile,v 1.62 2012/10/02 20:11:39 asau Exp $
#

DISTNAME=	Gauche-0.9.3.3
#PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gauche/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	enami@NetBSD.org
HOMEPAGE=	http://practical-scheme.net/gauche/
COMMENT=	R5RS Scheme implementation aimed to be a handy tool for daily works

DEPENDS+=		slib-[0-9]*:../../devel/slib

NOT_FOR_BULK_PLATFORM=	HPUX-*-*

.include "options.mk"

EVAL_PREFIX+=		SLIB_PREFIX=slib

MAKE_JOBS_SAFE=		no
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-slib=${SLIB_PREFIX}/share/slib
CONFIGURE_ARGS+=	--enable-threads=pthreads
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}

CHECK_BUILTIN.iconv:=	yes
.include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=	no

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
