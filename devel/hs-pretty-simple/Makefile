# $NetBSD: Makefile,v 1.12 2025/01/31 10:49:17 pho Exp $

DISTNAME=	pretty-simple-4.1.3.0
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Pretty printer for data types with a 'Show' instance
LICENSE=	modified-bsd

OPTPARSE_APPLICATIVE_EXECUTABLES=	\
	pretty-simple

# lib:pretty-simple
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../textproc/hs-prettyprinter-ansi-terminal/buildlink3.mk"

# exe:pretty-simple
.include "../../devel/hs-optparse-applicative/application.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
