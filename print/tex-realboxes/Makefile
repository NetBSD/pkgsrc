# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:45 rillig Exp $

DISTNAME=	realboxes
PKGNAME=	tex-${DISTNAME}-0.2
TEXLIVE_REV=	23581

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/realboxes
COMMENT=	Variants of common box-commands
LICENSE=	lppl-1.3c

DEPENDS+=	tex-collectbox-[0-9]*:../../print/tex-collectbox

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
