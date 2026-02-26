# $NetBSD: Makefile,v 1.35 2026/02/26 18:36:41 adam Exp $

DISTNAME=	patchutils-0.4.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=twaugh/}
EXTRACT_SUFX=	.tar.xz
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cyberelk.net/tim/software/patchutils/
COMMENT=	Some programs for manipulating patch files
LICENSE=	gnu-gpl-v2

# WARNING: xmlto not available so not building doc
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
DEPENDS+=	patch-[0-9]*:../../devel/patch

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash:run gmake perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-patch=${PREFIX}/bin/gpatch
TEST_TARGET=		check

REPLACE_BASH+=		scripts/editdiff.in
REPLACE_BASH+=		scripts/espdiff.in
REPLACE_BASH+=		scripts/move-to-front.in
REPLACE_PYTHON+=	patchview/patchview-wrapper

CHECK_PORTABILITY_SKIP+=	tests/rediff2/run-test

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
