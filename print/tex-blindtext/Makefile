# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:43 rillig Exp $

DISTNAME=	blindtext
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	25039

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/blindtext
COMMENT=	Producing 'blind' text for testing
LICENSE=	lppl-1.3c

.include "options.mk"

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
