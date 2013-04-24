# $NetBSD: Makefile,v 1.25 2013/04/24 10:06:50 sbd Exp $
#

DISTNAME=	netbsd-doc-print-1.3
PKGREVISION=	1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package including all packages to convert SGML->PDF/PS

DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	kpathsea>=6.0.0nb2:../../print/kpathsea
DEPENDS+=	netbsd-doc>=1.2:../../meta-pkgs/netbsd-doc
DEPENDS+=	openjade-[0-9]*:../../textproc/openjade
DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-cyrillic-[0-9]*:../../print/tex-cyrillic
DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
DEPENDS+=	tex-german-[0-9]*:../../print/tex-german
DEPENDS+=	tex-hyphen-german-[0-9]*:../../print/tex-hyphen-german
DEPENDS+=	tex-hyphen-russian-[0-9]*:../../print/tex-hyphen-russian
DEPENDS+=	tex-jadetex>=2.20nb1:../../print/tex-jadetex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-lh-[0-9]*:../../fonts/tex-lh
DEPENDS+=	tex-metafont-[0-9]*:../../fonts/tex-metafont
DEPENDS+=	tex-picinpar-[0-9]*:../../print/tex-picinpar
DEPENDS+=	tex-pslatex-[0-9]*:../../print/tex-pslatex
DEPENDS+=	tex-ly1-[0-9]*:../../fonts/tex-ly1
USE_TOOLS+=	gs:run

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
