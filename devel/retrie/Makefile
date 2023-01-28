# $NetBSD: Makefile,v 1.6 2023/01/28 02:40:22 pho Exp $

DISTNAME=	retrie-1.2.1.1
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Powerful, easy-to-use codemodding tool for Haskell
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	optparse-applicative

# If retrie is to be linked dynamically, it will depend on more than 80
# shared objects and the dynamic linker will spend too much time to resolve
# symbols on startup. This is unacceptable because retrie tends to be
# launched very frequently by editors and IDEs. This wastes storage, but
# time is more expensive than disks.
HASKELL_ENABLE_DYNAMIC_EXECUTABLE=	no

# retrie is built with optparse-applicative, and can generate shell
# completion scripts automatically.
.include "../../devel/hs-optparse-applicative/application.mk"

# lib:retrie
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-list-t/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-random-shuffle/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"

# exe:retrie
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../devel/hs-haskell-src-exts/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
