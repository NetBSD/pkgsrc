# $NetBSD: Makefile,v 1.9 2008/11/09 05:19:57 bjs Exp $
#

DISTNAME=		patchutils-0.3.0
CATEGORIES=		devel
MASTER_SITES=		http://cyberelk.net/tim/data/patchutils/stable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://cyberelk.net/tim/patchutils/index.html
COMMENT=		Some programs for manipulating patch files

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		patch-[0-9]*:../../devel/patch

BUILD_DEFS+=		GNU_PROGRAM_PREFIX

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-patch=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}patch

REPLACE_BASH+=		editdiff.in espdiff.in
USE_TOOLS+=		bash:run

.include "../../mk/bsd.pkg.mk"
