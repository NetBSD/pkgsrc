# $NetBSD: Makefile,v 1.4 2022/03/14 15:33:46 nikita Exp $

DISTNAME=	gash-0.3.0
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

.include "../../lang/guile30/module.mk"
.include "../../mk/bsd.pkg.mk"
