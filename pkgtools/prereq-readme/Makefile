# $NetBSD: Makefile,v 1.10 2025/09/21 21:22:40 wiz Exp $
#

PKGNAME=	prereq-readme-20050521
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	Tools required for pkgsrc README.html generation

META_PACKAGE=	yes

WRKSRC=		${WRKDIR}

# list all the tools we use
USE_TOOLS+=	awk
USE_TOOLS+=	cmp
USE_TOOLS+=	echo
USE_TOOLS+=	expr
USE_TOOLS+=	fgrep
USE_TOOLS+=	find
USE_TOOLS+=	grep
USE_TOOLS+=	gzip
USE_TOOLS+=	sed
USE_TOOLS+=	setenv
USE_TOOLS+=	sort

.include "../../mk/bsd.pkg.mk"
