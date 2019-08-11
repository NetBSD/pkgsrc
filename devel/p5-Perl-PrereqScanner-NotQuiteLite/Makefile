# $NetBSD: Makefile,v 1.4 2019/08/11 13:20:11 wiz Exp $
#

DISTNAME=	Perl-PrereqScanner-NotQuiteLite-0.9905
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Perl/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Perl-PrereqScanner-NotQuiteLite
COMMENT=	Tool to scan your Perl code for its prerequisites
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Dump>=0:../../devel/p5-Data-Dump
DEPENDS+=	p5-Module-CPANfile>=1.1004:../../devel/p5-Module-CPANfile
DEPENDS+=	p5-Module-Find>=0:../../devel/p5-Module-Find
DEPENDS+=	p5-Regexp-Trie>=0:../../devel/p5-Regexp-Trie

BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker-CPANfile>=0.06:../../devel/p5-ExtUtils-MakeMaker-CPANfile
BUILD_DEPENDS+=	p5-Test-FailWarnings-[0-9]*:../../devel/p5-Test-FailWarnings
BUILD_DEPENDS+=	p5-Test-UseAllModules>=0.17:../../devel/p5-Test-UseAllModules

PERL5_PACKLIST=	auto/Perl/PrereqScanner/NotQuiteLite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
