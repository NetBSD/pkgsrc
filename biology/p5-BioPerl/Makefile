# $NetBSD: Makefile,v 1.2 2017/05/07 15:09:38 mef Exp $

DISTNAME=	BioPerl-1.007001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	biology perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/C/CJ/CJFIELDS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~cjfields/BioPerl/Bio/Perl.pm
COMMENT=	Functional access to BioPerl for people who don't know objects
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Data-Stag-[0-9]*:../../devel/p5-Data-Stag
BUILD_DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most
BUILD_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Bio/.packlist
USE_LANGUAGES=		# none

REPLACE_PERL+=	scripts/utilities/bp_find-blast-matches.pl
REPLACE_PERL+=	scripts/seq/bp_seqcut.pl
REPLACE_PERL+=	scripts/Bio-DB-SeqFeature-Store/bp_seqfeature_gff3.pl
REPLACE_PERL+=	scripts/seq/bp_seqpart.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
