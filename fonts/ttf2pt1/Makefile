# $NetBSD: Makefile,v 1.30 2022/06/28 11:33:54 wiz Exp $
#

DISTNAME=	ttf2pt1-3.4.4
PKGREVISION=	16
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ttf2pt1/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://ttf2pt1.sourceforge.net/
COMMENT=	TrueType font converter to Postscript type 1

DEPENDS+=	t1utils-[0-9]*:../../fonts/t1utils

USE_TOOLS+=	perl:run

REPLACE_PERL+=	app/TeX/cjk-latex-config app/TeX/sfd2map
REPLACE_PERL+=	other/cntstems.pl other/lst.pl other/showdf other/showg
REPLACE_PERL+=	scripts/forceiso scripts/frommap scripts/html2man
REPLACE_PERL+=	scripts/inst_dir scripts/t1fdir scripts/trans

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
