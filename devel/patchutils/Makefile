# $NetBSD: Makefile,v 1.4 2005/07/16 01:19:09 jlam Exp $
#

DISTNAME=		patchutils-0.2.30
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://cyberelk.net/tim/data/patchutils/stable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://cyberelk.net/tim/patchutils/index.html
COMMENT=		Some programs for manipulating patch files

DEPENDS+=               patch-[0-9]*:../../devel/patch

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-patch=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}patch

.include "../../mk/bsd.pkg.mk"
