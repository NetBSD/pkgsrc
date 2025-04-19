# $NetBSD: Makefile,v 1.117 2025/04/19 07:58:21 wiz Exp $

DISTNAME=	hydra-7.5
PKGREVISION=	60
CATEGORIES=	security
MASTER_SITES=	http://freeworld.thc.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://freeworld.thc.org/thc-hydra/
COMMENT=	Login password cracker
LICENSE=	gnu-agpl-v3

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	BUILDLINK_DIR=${BUILDLINK_DIR:Q}

LDFLAGS.SunOS+=		-lsocket -lnsl
LDFLAGS.NetBSD+=	-pthread

.include "options.mk"

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
