# $NetBSD: Makefile,v 1.7 2003/09/14 14:04:31 recht Exp $
#

DISTNAME=	Python-2.3
PKGNAME=	python23-2.3
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.3/
EXTRACT_SUFX=	.tgz

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-threads
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	OPT="${CFLAGS}"
# XXX configure would pull in libpthread
CONFIGURE_ENV+=		ac_cv_search_sem_init=no

INSTALL_TARGET=	altinstall

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc2.3

# XXX should be done by the Python install process
post-install:
	${LN} -s ${PREFIX}/lib/libpython2.3.so.1.0 \
		${PREFIX}/lib/libpython2.3.so

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LOWER_OPSYS=   sunos
.endif

.if ${OPSYS} == "Darwin" || ${OPSYS} == "IRIX"
PLIST_SUBST+=  PY_PLATNAME=${LOWER_OPSYS}
.else
PLIST_SUBST+=  PY_PLATNAME=${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif

.if ${OPSYS} != "NetBSD"
.include "../../databases/db/buildlink2.mk"
CPPFLAGS+=	-I${BUILDLINK_PREFIX.db}/include/db2
.endif

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
