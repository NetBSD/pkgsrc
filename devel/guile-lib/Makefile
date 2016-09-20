# $NetBSD: Makefile,v 1.26 2016/09/20 00:37:37 gdt Exp $

DISTNAME=	guile-lib-0.2.3
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.gnu.org/releases/guile-lib/
# http://download.gna.org/guile-lib/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/guile-lib/
COMMENT=	Library functions for Guile, implemented in Scheme

GNU_CONFIGURE=	yes

USE_TOOLS+=	gmake makeinfo pkg-config
TEXINFO_REQD=	4.2
INFO_FILES=	yes
TEST_TARGET=	check

# guile-lib uses the install(1) feature that missing intermediate
# directories are created automatically, which e.g. NetBSD's doesn't
# support, so we have to precreate the directories
INSTALLATION_DIRS+=	share/guile/site/config
INSTALLATION_DIRS+=	share/guile/site/container
INSTALLATION_DIRS+=	share/guile/site/debugging
INSTALLATION_DIRS+=	share/guile/site/graph
INSTALLATION_DIRS+=	share/guile/site/io
INSTALLATION_DIRS+=	share/guile/site/logging
INSTALLATION_DIRS+=	share/guile/site/math
INSTALLATION_DIRS+=	share/guile/site/os
INSTALLATION_DIRS+=	share/guile/site/scheme
INSTALLATION_DIRS+=	share/guile/site/search
INSTALLATION_DIRS+=	share/guile/site/srfi
INSTALLATION_DIRS+=	share/guile/site/string
INSTALLATION_DIRS+=	share/guile/site/sxml
INSTALLATION_DIRS+=	share/guile/site/sxml/ssax
INSTALLATION_DIRS+=	share/guile/site/sxml/upstream
INSTALLATION_DIRS+=	share/guile/site/term
INSTALLATION_DIRS+=	share/guile/site/texinfo
INSTALLATION_DIRS+=	share/guile/site/text

.include "../../lang/guile20/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
