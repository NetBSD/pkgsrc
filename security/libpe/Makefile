# $NetBSD: Makefile,v 1.3 2022/07/10 02:40:52 khorben Exp $

.include "../../security/libpe/Makefile.common"

DISTNAME=	${GITHUB_PROJECT}-${PEV_VERSION}
PKGREVISION=	1
GITHUB_PROJECT=	libpe
GITHUB_TAG=	ce39b127328e3863e08163962f7ecc768eb2555e

COMMENT=	The PE library used by pev - the PE file toolkit
LICENSE=	gnu-lgpl-v3

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
