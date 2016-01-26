# $NetBSD: Makefile,v 1.69 2016/01/26 14:46:46 szptvlfn Exp $
#

DISTNAME=	Gauche-0.9.4
#PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gauche/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	enami@NetBSD.org
HOMEPAGE=	http://practical-scheme.net/gauche/
COMMENT=	R7RS Scheme implementation aimed to be a handy tool for daily works
LICENSE=	modified-bsd # see work/${DISTNAME}/COPYING

DEPENDS+=		slib-[0-9]*:../../devel/slib

.include "options.mk"

MAKE_JOBS_SAFE=		no
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-slib=${LOCALBASE}/share/slib
CONFIGURE_ARGS+=	--enable-threads=pthreads
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}

CHECK_BUILTIN.iconv:=	yes
.include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=	no

.if !empty(USE_BUILTIN.iconv:M[nN][oO])
CONFIGURE_ARGS+=	--with-iconv-lib=${BUILDLINK_LIBNAME.iconv}
ICONV_LDFLAGS=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.iconv}/lib \
		-L${BUILDLINK_PREFIX.iconv}/lib
ALL_ENV+=		\
	ICONV_LDFLAGS=${ICONV_LDFLAGS:Q}
.endif

USE_LANGUAGES=	c c99
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
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
