# $NetBSD: Makefile,v 1.13 2023/11/08 13:18:45 wiz Exp $

DISTNAME=	hiedb-0.4.3.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Generates a references DB from .hie files
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	algebraic-graphs

# hiedb is built with optparse-applicative, and can generate shell
# completion scripts automatically.
OPTPARSE_APPLICATIVE_EXECUTABLES+=	hiedb
.include "../../devel/hs-optparse-applicative/application.mk"

# lib:hiedb
.include "../../math/hs-algebraic-graphs/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-hie-compat/buildlink3.mk"
.include "../../textproc/hs-lucid/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../databases/hs-sqlite-simple/buildlink3.mk"
.include "../../devel/hs-terminal-size/buildlink3.mk"

# exe:hiedb
.include "../../devel/hs-ghc-paths/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
