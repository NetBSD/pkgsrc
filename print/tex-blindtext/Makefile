# $NetBSD: Makefile,v 1.2 2019/12/06 20:19:01 markd Exp $

DISTNAME=	blindtext
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	25039

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/blindtext
COMMENT=	Producing 'blind' text for testing
LICENSE=	lppl-1.3c

.include "options.mk"

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
