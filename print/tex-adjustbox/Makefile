# $NetBSD: Makefile,v 1.9 2020/01/18 23:33:31 rillig Exp $

DISTNAME=	adjustbox
PKGNAME=	tex-${DISTNAME}-1.2
TEXLIVE_REV=	49596

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ctan.org/pkg/adjustbox
COMMENT=	Graphics package-alike macros for general boxes
LICENSE=	lppl-1.3c

DEPENDS+=	tex-collectbox-[0-9]*:../../print/tex-collectbox

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
