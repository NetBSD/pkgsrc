# $NetBSD: Makefile,v 1.27 2022/06/28 11:35:38 wiz Exp $

DISTNAME=	munge-0.5.13
PKGREVISION=	7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=dun/}
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dun.github.io/munge/
COMMENT=	Authentication service for creating and validating credentials
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		perl pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
INSTALLATION_DIRS+=	lib/pkgconfig

OWN_DIRS=	${VARBASE}/lib/munge
OWN_DIRS+=	${VARBASE}/log/munge
OWN_DIRS+=	${VARBASE}/run/munge
OWN_DIRS+=	etc/munge

BUILD_DEFS+=	VARBASE

RCD_SCRIPTS+=	munge

SUBST_CLASSES+=		init
SUBST_STAGE.init=	post-build
SUBST_FILES.init=	${WRKSRC}/src/etc/munge.init
SUBST_FILES.init+=	${WRKSRC}/src/etc/munge.sysconfig
SUBST_SED.init=		-e 's|USER="munge"|USER="daemon"|g'
SUBST_SED.init+=	-e 's|GROUP="munge"|GROUP="daemon"|g'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
