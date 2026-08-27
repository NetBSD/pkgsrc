# $NetBSD: Makefile,v 1.1 2026/08/27 20:49:57 leot Exp $

DISTNAME=	opentofu-1.11.14
PKGNAME=	${DISTNAME:S/opentofu/&111/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=opentofu/}
GITHUB_PROJECT=	opentofu
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://opentofu.org/
COMMENT=	Open source infrastructure as code
LICENSE=	mpl-2.0

SUBST_CLASSES+=			providers-prefix
SUBST_STAGE.providers-prefix=	pre-configure
SUBST_MESSAGE.providers-prefix=	Honor providers installed via pkgsrc
SUBST_FILES.providers-prefix=	cmd/tofu/provider_source.go
SUBST_VARS.providers-prefix=	PREFIX

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/${GOPATH_BIN}/tofu ${DESTDIR}${PREFIX}/bin/tofu111

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
