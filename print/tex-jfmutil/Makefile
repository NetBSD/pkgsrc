# $NetBSD: Makefile,v 1.2 2021/02/15 04:39:57 markd Exp $

DISTNAME=	jfmutil
PKGNAME=	tex-${DISTNAME}-1.3.1
TEXLIVE_REV=	55044

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jfmutil
COMMENT=	Utility to process pTeX-extended TFM and VF
LICENSE=	mit

USE_TOOLS+=	perl:run

INSTALLATION_DIRS+=	bin

REPLACE_PERL=	texmf-dist/scripts/jfmutil/jfmutil.pl

post-install:
	${LN} -sf ../share/texmf-dist/scripts/jfmutil/jfmutil.pl \
		${DESTDIR}${PREFIX}/bin/jfmutil

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
