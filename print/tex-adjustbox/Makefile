# $NetBSD: Makefile,v 1.8 2019/12/06 20:18:45 markd Exp $

DISTNAME=	adjustbox
PKGNAME=	tex-${DISTNAME}-1.2
TEXLIVE_REV=	49596

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ctan.org/pkg/adjustbox
COMMENT=	Graphics package-alike macros for general boxes
LICENSE=	lppl-1.3c

DEPENDS+=	tex-collectbox-[0-9]*:../../print/tex-collectbox

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
