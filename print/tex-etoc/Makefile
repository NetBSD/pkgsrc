# $NetBSD: Makefile,v 1.3 2019/12/06 20:19:32 markd Exp $

DISTNAME=	etoc
PKGNAME=	tex-${DISTNAME}-1.09
TEXLIVE_REV=	50317

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/etoc
COMMENT=	Completely customisable TOCs
LICENSE=	lppl-1.3c

DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
