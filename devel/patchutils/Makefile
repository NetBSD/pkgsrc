# $NetBSD: Makefile,v 1.1.1.1 2004/07/24 08:45:26 recht Exp $
#

DISTNAME=		patchutils-0.2.30
CATEGORIES=		devel
MASTER_SITES=		http://cyberelk.net/tim/data/patchutils/stable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://cyberelk.net/tim/patchutils/index.html
COMMENT=		Some programs for manipulating patch files

DEPENDS+=               patch-[0-9]*:../../devel/patch

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_PERL5=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-patch=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}patch

.include "../../mk/bsd.pkg.mk"
