# $NetBSD: Makefile,v 1.8 2020/06/17 09:54:09 bsiegert Exp $

GITHUB_TAG=		v${PKGVERSION_NOREV}
DISTNAME=		go-compress-1.9.1
PKGREVISION=		6
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=klauspost/}
GITHUB_PROJECT=		compress

MAINTAINER=		nikita@NetBSD.org
HOMEPAGE=		https://github.com/klauspost/compress/
COMMENT=		Optimized compression packages for Go
LICENSE=		modified-bsd

GO_SRCPATH=		github.com/klauspost/compress
GO_DIST_BASE=		compress-${PKGVERSION_NOREV}

# This is a Linux specific fuzzing file.
# This is an sh script, no Bash syntax found.
SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-build
SUBST_FILES.bash=	${WRKDIR}/src/github.com/klauspost/compress/fuzzit.sh
SUBST_SED.bash=		-e "s,bash,sh,g"

.include "../../devel/go-cpuid/buildlink3.mk"
.include "../../security/go-xxhash/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
