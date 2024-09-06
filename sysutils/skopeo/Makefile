# $NetBSD: Makefile,v 1.2 2024/09/06 18:48:58 bsiegert Exp $

DISTNAME=	skopeo-1.14.3
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=containers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/containers/skopeo/
COMMENT=	Tool for manipulating OCI containers
LICENSE=	apache-2.0

USE_TOOLS+=	gmake gsed pkg-config

.include "../../mk/bsd.prefs.mk"
.include "../../lang/go/version.mk"

EGDIR=			${PREFIX}/share/examples
PKG_SYSCONFSUBDIR=	containers

CONF_FILES+=	${EGDIR}/containers/policy.json ${PKG_SYSCONFDIR}/policy.json
CONF_FILES+=	${EGDIR}/containers/registries.d/default.yaml ${PKG_SYSCONFDIR}/registries.d/default.yaml

MAKE_ENV+=	CONTAINERSCONFDIR=${EGDIR}/containers \
		MANDIR=${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-configure
SUBST_MESSAGE.fix-paths=	Substituting paths.
SUBST_FILES.fix-paths=		vendor/github.com/containers/image/v5/signature/policy_paths_common.go
SUBST_VARS.fix-paths+=		PKG_SYSCONFDIR

TOOL_DEPENDS+=	go-md2man-[0-9]*:../../textproc/go-md2man
.include "../../security/gpgme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
