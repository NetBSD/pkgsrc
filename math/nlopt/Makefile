# $NetBSD: Makefile,v 1.2 2021/09/18 05:06:06 mef Exp $

VERSION=		2.6.2
DISTNAME=		nlopt-${VERSION}
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=stevengj/}
GITHUB_TAG=		v${VERSION}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ab-initio.mit.edu/nlopt/
COMMENT=		Nonlinear optimization library
LICENSE=		gnu-lgpl-v2.1 OR mit

USE_CMAKE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
