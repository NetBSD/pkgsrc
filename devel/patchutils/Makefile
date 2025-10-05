# $NetBSD: Makefile,v 1.33 2025/10/05 15:22:53 adam Exp $

DISTNAME=	patchutils-0.4.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=twaugh/}
EXTRACT_SUFX=	.tar.xz
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cyberelk.net/tim/software/patchutils/
COMMENT=	Some programs for manipulating patch files
LICENSE=	gnu-gpl-v2

# WARNING: xmlto not available so not building doc
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
DEPENDS+=	patch-[0-9]*:../../devel/patch

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash:run gmake perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-patch=${PREFIX}/bin/gpatch

REPLACE_BASH+=		scripts/editdiff.in scripts/espdiff.in
REPLACE_PYTHON+=	patchview/gitdiff
REPLACE_PYTHON+=	patchview/gitshow

CHECK_PORTABILITY_SKIP+=	tests/rediff2/run-test

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
