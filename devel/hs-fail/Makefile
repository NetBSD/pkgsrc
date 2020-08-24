# $NetBSD: Makefile,v 1.2 2020/08/24 12:15:50 pho Exp $

DISTNAME=	fail-4.9.0.0
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Forward-compatible MonadFail class
LICENSE=	modified-bsd

# This package becomes essentially blank when built with GHC >=
# 8.0. Haddock complains when there are no input files.
HASKELL_ENABLE_HADDOCK_DOCUMENTATION=	no

# Do not install the LICENCE file because ../../mk/haskell.mk can not
# correctly substitute the path to doc files when the package is
# blank.
post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/doc

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
