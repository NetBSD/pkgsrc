# $NetBSD: Makefile,v 1.1 2022/05/16 18:08:00 tpaul Exp $

DISTNAME=	vultr-cli-2.14.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=vultr/}

DIST_SUBDIR=	${DISTNAME}
MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://github.com/vultr/vultr-cli/
COMMENT=	Official command line tool for Vultr services
LICENSE=	apache-2.0

GO_DIST_BASE=		${PKGNAME_NOREV}
GO_SRCPATH=		github.com/vultr/vultr-cli/v2

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/v2 ${DESTDIR}${PREFIX}/bin/vultr-cli


.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
