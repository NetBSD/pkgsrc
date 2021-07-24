# $NetBSD: Makefile,v 1.76 2021/07/24 14:50:42 yhardy Exp $
#

DISTNAME=	Gauche-0.9.10
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gauche/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	enami@NetBSD.org
HOMEPAGE=	https://practical-scheme.net/gauche/
COMMENT=	R7RS Scheme implementation aimed to be a handy tool for daily works
LICENSE=	modified-bsd # see work/${DISTNAME}/COPYING

DEPENDS+=		slib-[0-9]*:../../devel/slib

.include "options.mk"

MAKE_JOBS_SAFE=		no
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has several configure programs
CONFIGURE_ARGS+=	--with-slib=${LOCALBASE}/share/slib
CONFIGURE_ARGS+=	--enable-threads=pthreads
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

USE_LANGUAGES=	c c99
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake gzip makeinfo
TEST_TARGET=	check
INFO_FILES=	yes
TEXINFO_REQD=	5.0

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
