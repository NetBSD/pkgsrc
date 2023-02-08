# $NetBSD: Makefile,v 1.4 2023/02/08 21:53:03 nikita Exp $

DISTNAME=	guile-syntax-highlight-0.2.0
CATEGORIES=	textproc
MASTER_SITES=	https://files.dthompson.us/guile-syntax-highlight/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://dthompson.us/projects/guile-syntax-highlight.html
COMMENT=	General-purpose syntax highlighting library for GNU Guile
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../lang/guile30/module.mk"
.include "../../mk/bsd.pkg.mk"
