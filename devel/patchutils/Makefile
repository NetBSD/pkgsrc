# $NetBSD: Makefile,v 1.24 2019/08/11 13:20:49 wiz Exp $

DISTNAME=		patchutils-0.3.4
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://cyberelk.net/tim/data/patchutils/stable/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cyberelk.net/tim/software/patchutils/
COMMENT=		Some programs for manipulating patch files
LICENSE=		gnu-gpl-v2

DEPENDS+=		patch-[0-9]*:../../devel/patch
#  WARNING: xmlto not available so not building doc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-patch=${PREFIX}/bin/gpatch

CHECK_PORTABILITY_SKIP+=tests/rediff2/run-test
REPLACE_BASH+=		scripts/editdiff.in scripts/espdiff.in
USE_TOOLS+=		bash:run

.include "../../mk/bsd.pkg.mk"
