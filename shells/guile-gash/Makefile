# $NetBSD: Makefile,v 1.3 2021/12/17 13:26:23 nikita Exp $

DISTNAME=	gash-0.2.0
PKGNAME=	guile-${DISTNAME}
CATEGORIES=	shells
MASTER_SITES=	http://download.savannah.nongnu.org/releases/gash/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://git.savannah.nongnu.org/cgit/gash.git
COMMENT=	POSIX-compatible shell written in Guile Scheme
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
GUILE_NEED_BOOTSTRAP=	yes
TEXINFO_REQD=		5.1
USE_TOOLS+=		pkg-config gmake makeinfo

INFO_FILES=		YES

.include "../../lang/guile22/module.mk"
.include "../../mk/bsd.pkg.mk"
