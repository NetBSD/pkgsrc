# $NetBSD: Makefile,v 1.2 2016/01/30 03:26:05 markd Exp $

DISTNAME=	abc.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.0
TEXLIVE_REV=	15878

MAINTAINER=	nico@orgrim.net
COMMENT=	Documentation for tex-abc
LICENSE=	lppl-1.2

CONFLICTS+=	tex-abc<=1.0

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
