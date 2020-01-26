# $NetBSD: Makefile,v 1.25 2020/01/26 17:30:40 rillig Exp $

DISTNAME=	dact-0.8.42
CATEGORIES=	archivers
MASTER_SITES=	http://www.rkeene.org/devel/dact/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rkeene.org/oss/dact/
COMMENT=	Dynamic adaptive compression tool
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/dact

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
