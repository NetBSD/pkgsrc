# $NetBSD: Makefile,v 1.93 2020/11/05 09:09:02 ryoon Exp $
#

DISTNAME=	hydra-7.5
PKGREVISION=	37
CATEGORIES=	security
MASTER_SITES=	http://freeworld.thc.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://freeworld.thc.org/thc-hydra/
COMMENT=	Login password cracker
LICENSE=	gnu-agpl-v3

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	YES

CONFIGURE_ENV+=	BUILDLINK_DIR=${BUILDLINK_DIR:Q}

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

INSTALLATION_DIRS=	bin

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "options.mk"

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
