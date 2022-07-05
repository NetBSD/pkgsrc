# $NetBSD: Makefile,v 1.6 2022/07/05 16:12:50 tpaul Exp $

VERSION=	2.14.2
DISTNAME=	vultr-cli-${VERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=vultr/}
GITHUB_TAG=	v${VERSION}

DIST_SUBDIR=	${DISTNAME}
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vultr/vultr-cli/
COMMENT=	Official command line tool for Vultr services
LICENSE=	apache-2.0

GO_DIST_BASE=		${PKGNAME_NOREV}
GO_SRCPATH=		github.com/vultr/vultr-cli/v2

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/v2 ${DESTDIR}${PREFIX}/bin/vultr-cli


.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
