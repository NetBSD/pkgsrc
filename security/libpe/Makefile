# $NetBSD: Makefile,v 1.1 2021/05/29 23:23:42 khorben Exp $

DISTNAME=	${GITHUB_PROJECT}-0.81
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=merces/}
GITHUB_PROJECT=	libpe
GITHUB_TAG=	ce39b127328e3863e08163962f7ecc768eb2555e

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://pev.sourceforge.io/
COMMENT=	The PE library used by pev - the PE file toolkit
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	gmake

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	prefix=${PREFIX}

INSTALLATION_DIRS=	include/libpe

post-install:
	for include in ${WRKSRC}/include/libpe/*.h; do \
		${INSTALL_DATA} $${include} ${DESTDIR}${PREFIX}/include/libpe; \
	done

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
