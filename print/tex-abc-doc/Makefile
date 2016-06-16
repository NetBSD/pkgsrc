# $NetBSD: Makefile,v 1.3 2016/06/16 04:05:58 markd Exp $

DISTNAME=	abc.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.0b
TEXLIVE_REV=	41157

MAINTAINER=	nico@orgrim.net
COMMENT=	Documentation for tex-abc
LICENSE=	lppl-1.2

CONFLICTS+=	tex-abc<=1.0

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
