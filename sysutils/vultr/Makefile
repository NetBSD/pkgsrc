# $NetBSD: Makefile,v 1.7 2019/04/16 18:41:19 bsiegert Exp $

DISTNAME=		vultr-1.15.0
PKGREVISION=		6
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=JamesClonk/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://jamesclonk.github.io/vultr/
COMMENT=		CLI and API client library for Vultr
LICENSE=		mit

GO_DIST_BASE=		${DISTNAME}
GO_SRCPATH=		github.com/JamesClonk/vultr

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/vultr ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
