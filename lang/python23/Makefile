# $NetBSD: Makefile,v 1.2 2003/08/06 11:51:30 drochner Exp $
#

DISTNAME=	Python-2.3
PKGNAME=	python23-2.3
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
# XXX configure would pull in libpthread
CONFIGURE_ENV+=		ac_cv_search_sem_init=no

INSTALL_TARGET=	altinstall

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc2.3

# XXX should be done by the Python install process
post-install:
	${LN} -s ${PREFIX}/lib/libpython2.3.so.1.0 \
		${PREFIX}/lib/libpython2.3.so

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
