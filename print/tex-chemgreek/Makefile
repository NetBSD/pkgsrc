# $NetBSD: Makefile,v 1.2 2019/12/06 20:19:07 markd Exp $

DISTNAME=	chemgreek
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	42758

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/chemgreek
COMMENT=	Upright Greek letters in chemistry
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
