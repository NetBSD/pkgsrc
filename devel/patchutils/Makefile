# $NetBSD: Makefile,v 1.16 2014/05/29 23:36:29 wiz Exp $
#

DISTNAME=		patchutils-0.3.2
#KGREVISION=		2
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://cyberelk.net/tim/data/patchutils/stable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cyberelk.net/tim/patchutils/index.html
COMMENT=		Some programs for manipulating patch files

DEPENDS+=		patch-[0-9]*:../../devel/patch

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-patch=${PREFIX}/bin/gpatch

CHECK_PORTABILITY_SKIP+=tests/rediff2/run-test
REPLACE_BASH+=		editdiff.in espdiff.in
USE_TOOLS+=		bash:run

.include "../../mk/bsd.pkg.mk"
