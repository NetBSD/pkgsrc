# $NetBSD: Makefile,v 1.2 2025/12/12 03:00:28 manu Exp $
DISTNAME=	OpenARC-1.3.0
PKGNAME=	flowerysong-${DISTNAME:tl}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=flowerysong/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flowerysong/OpenARC
COMMENT=	Open source ARC library, MTA filter implementation and tools
LICENSE=	modified-bsd

CONFLICT+=	openarc-[0-9]*

RCD_SCRIPTS=	openarc

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf automake pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-milter=${BUILDLINK_PREFIX.libmilter}

SUBST_CLASSES+=			interpreter
SUBST_STAGE.interpreter=	pre-configure
SUBST_MESSAGE.interpreter=	Substituting /usr/bin/env python3 interpreter
SUBST_FILES.interpreter=	contrib/openarc-keygen
SUBST_SED.interpreter+=	-e "s,\#! */usr/bin/env *python3,\#!${PYTHONBIN},"

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	${EGDIR}

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

post-install:
	${INSTALL_DATA} ${WRKSRC}/openarc/openarc.conf.sample \
		${DESTDIR}${EGDIR}/

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
