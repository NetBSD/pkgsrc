# $NetBSD: Makefile,v 1.31 2022/03/05 19:39:19 gdt Exp $

DISTNAME=	guile-lib-0.2.7
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.gnu.org/releases/guile-lib/
# http://download.gna.org/guile-lib/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/guile-lib/
COMMENT=	Library functions for Guile, implemented in Scheme

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-guile-site=yes

USE_TOOLS+=	gmake makeinfo pkg-config
TEXINFO_REQD=	4.2
INFO_FILES=	yes
TEST_TARGET=	check

# guile-lib uses the install(1) feature that missing intermediate
# directories are created automatically, which e.g. NetBSD's doesn't
# support, so we have to precreate the directories
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/config
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/container
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/debugging
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/graph
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/io
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/logging
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/math
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/os
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/scheme
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/search
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/string
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/term
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/texinfo
INSTALLATION_DIRS+=	guile/2.2/share/guile/site/text

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
