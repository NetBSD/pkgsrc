# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:19 rillig Exp $

DISTNAME=	keycommand
PKGNAME=	tex-${DISTNAME}-3.1415
TEXLIVE_REV=	18042

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/keycommand
COMMENT=	Simple creation of commands with key-value arguments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
