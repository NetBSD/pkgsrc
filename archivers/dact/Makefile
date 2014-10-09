# $NetBSD: Makefile,v 1.22 2014/10/09 14:05:51 wiz Exp $

DISTNAME=	dact-0.8.41
CATEGORIES=	archivers
MASTER_SITES=	http://www.rkeene.org/devel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rkeene.org/devel/dact/
COMMENT=	Dynamic adaptive compression tool

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/dact

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
