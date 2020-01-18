# $NetBSD: Makefile,v 1.6 2020/01/18 23:34:17 rillig Exp $

DISTNAME=	ifmtarg
PKGNAME=	tex-${DISTNAME}-1.2b
TEXLIVE_REV=	47544

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ifmtarg
COMMENT=	If-then-else command for processing potentially empty arguments
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
