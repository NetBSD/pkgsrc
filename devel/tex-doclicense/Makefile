# $NetBSD: Makefile,v 1.2 2018/05/06 02:33:55 markd Exp $

DISTNAME=	doclicense
PKGNAME=	tex-${DISTNAME}-1.7.0
TEXLIVE_REV=	46661

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/doclicense
COMMENT=	Support for putting documents under a license
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-xifthen-[0-9]*:../../devel/tex-xifthen
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
