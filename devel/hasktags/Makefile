# $NetBSD: Makefile,v 1.7 2024/05/09 01:31:43 pho Exp $

DISTNAME=	hasktags-0.73.0
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Produces ctags "tags" and etags "TAGS" files for Haskell programs
LICENSE=	modified-bsd

OPTPARSE_APPLICATIVE_EXECUTABLES+=	\
	hasktags

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	json

# lib:hasktags
.include "../../converters/hs-json/buildlink3.mk"
.include "../../devel/hs-microlens-platform/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"

# exe:hasktags
.include "../../devel/hs-optparse-applicative/application.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
