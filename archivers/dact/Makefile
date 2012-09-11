# $NetBSD: Makefile,v 1.21 2012/09/11 19:46:53 asau Exp $

DISTNAME=	dact-0.8.41
CATEGORIES=	archivers
MASTER_SITES=	http://www.rkeene.org/devel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rkeene.org/devel/dact/
COMMENT=	Dynamic adaptive compression tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/dact

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
