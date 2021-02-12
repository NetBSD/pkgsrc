# $NetBSD: Makefile,v 1.1 2021/02/12 02:15:02 markd Exp $

DISTNAME=	jfmutil
PKGNAME=	tex-${DISTNAME}-1.3.1
TEXLIVE_REV=	55044

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jfmutil
COMMENT=	Utility to process pTeX-extended TFM and VF
LICENSE=	mit

INSTALLATION_DIRS+=	bin

REPLACE_PERL=	texmf-dist/scripts/jfmutil/jfmutil.pl

post-install:
	${LN} -sf ../share/texmf-dist/scripts/jfmutil/jfmutil.pl \
		${DESTDIR}${PREFIX}/bin/jfmutil

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
