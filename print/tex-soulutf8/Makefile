# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:44 markd Exp $

DISTNAME=	soulutf8
PKGNAME=	tex-${DISTNAME}-1.2
TEXLIVE_REV=	53163

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/soulutf8
COMMENT=	Permit use of UTF-8 characters in soul
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etexcmds-[0-9]*:../../print/tex-etexcmds
DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-soul-[0-9]*:../../print/tex-soul

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
