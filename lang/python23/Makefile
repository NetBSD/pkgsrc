# $NetBSD: Makefile,v 1.1.1.1 2003/08/04 08:25:23 drochner Exp $
#

DISTNAME=	Python-2.3
PKGNAME=	python23-2.3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.3/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
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

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
