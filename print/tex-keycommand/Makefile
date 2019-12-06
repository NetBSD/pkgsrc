# $NetBSD: Makefile,v 1.2 2019/12/06 20:21:46 markd Exp $

DISTNAME=	keycommand
PKGNAME=	tex-${DISTNAME}-3.1415
TEXLIVE_REV=	18042

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/keycommand
COMMENT=	Simple creation of commands with key-value arguments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
