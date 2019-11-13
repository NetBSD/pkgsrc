# $NetBSD: Makefile,v 1.1 2019/11/13 10:04:19 ng0 Exp $

DISTNAME=	gash-0.1
PKGNAME=	guile-${DISTNAME}
CATEGORIES=	shells
MASTER_SITES=	http://download.savannah.nongnu.org/releases/gash/

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://git.savannah.nongnu.org/cgit/gash.git
COMMENT=	POSIX-compatible shell written in Guile Scheme
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
GUILE_NEED_BOOTSTRAP=	yes

USE_TOOLS+=		pkg-config

INFO_FILES=		YES

.include "../../lang/guile22/module.mk"
.include "../../mk/bsd.pkg.mk"
