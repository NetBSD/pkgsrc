# $NetBSD: Makefile,v 1.1 2026/02/07 01:00:44 gdt Exp $

DISTNAME=	erlydtl-0.15.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=erlydtl/}
GITHUB_PROJECT=	erlydtl
#GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erlydtl/erlydtl/
COMMENT=	Ccompiles Django Template Language to Erlang bytecode
LICENSE=	mit

USE_LANGUAGES=	# none

# Fix "#!/usr/bin/env escript"
SUBST_CLASSES+=		escript
SUBST_FILES.escript=	bin/erlydtl_compile
SUBST_SED.escript=	-e 's,/usr/bin/env escript,${PREFIX}/bin/escript,'
SUBST_STAGE.escript=	post-build

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
