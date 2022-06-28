# $NetBSD: Makefile,v 1.6 2022/06/28 11:31:49 wiz Exp $

GITHUB_TAG=	81f185261c8863c5b84344ee31192870be939faf
DISTNAME=	ninka-1.3.2pre20180106
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dmgerman/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://ninka.turingmachine.org/
COMMENT=	License identification tool for Source Code
LICENSE=	gnu-gpl-v2

DEPENDS+=		p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=		p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
DEPENDS+=		p5-Spreadsheet-WriteExcel-[0-9]*:../../math/p5-Spreadsheet-WriteExcel
DEPENDS+=		p5-IO-CaptureOutput-[0-9]*:../../devel/p5-IO-CaptureOutput
TEST_DEPENDS+=		p5-Test-Pod>=0:../../devel/p5-Test-Pod
TEST_DEPENDS+=		p5-Test-Strict>=0:../../devel/p5-Test-Strict

USE_TOOLS+=		pax perl:run
USE_LANGUAGES=		# none
WRKSRC=			${WRKDIR}/ninka-${GITHUB_TAG}
PERL5_PACKLIST=		auto/Ninka/.packlist

# See https://github.com/dmgerman/ninka/pull/41
SUBST_CLASSES+=		regex
SUBST_STAGE.regex=	pre-configure
SUBST_FILES.regex=	lib/Ninka/SentenceExtractor.pm
SUBST_SED.regex=	-e s/1-2/1,2/

REPLACE_PERL+=		*/*.pl bin/*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
