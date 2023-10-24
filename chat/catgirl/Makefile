# $NetBSD: Makefile,v 1.3 2023/10/24 22:08:19 wiz Exp $

DISTNAME=	catgirl-2.1
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	https://git.causal.agency/catgirl/snapshot/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.causal.agency/catgirl/about/
COMMENT=	TLS-only terminal IRC client
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

HAS_CONFIGURE=	yes

MAKE_FLAGS=	MANDIR=${PREFIX}/${PKGMANDIR}

USE_CC_FEATURES+=	c11

SUBST_CLASSES+=		ssl
SUBST_STAGE.ssl=	pre-configure
SUBST_MESSAGE.ssl=	Correcting the hardcoded path to OpenSSL.
SUBST_FILES.ssl+=	configure
SUBST_SED.ssl+=		-e "s,OPENSSL_BIN /usr/bin/openssl,OPENSSL_BIN ${SSLBASE}/bin/openssl,g"
SUBST_SED.ssl+=		-e "s,OPENSSL_BIN /bin/openssl,OPENSSL_BIN ${SSLBASE}/bin/openssl,g"

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../security/libretls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
