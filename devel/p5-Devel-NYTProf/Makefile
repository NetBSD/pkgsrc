# $NetBSD: Makefile,v 1.41 2023/06/06 12:40:47 riastradh Exp $

DISTNAME=	Devel-NYTProf-6.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-NYTProf
COMMENT=	Powerful feature-rich Perl 5 source code profiler
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=		p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
TOOL_DEPENDS+=		p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
TOOL_DEPENDS+=		p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PERL5_PACKLIST=		auto/Devel/NYTProf/.packlist
REPLACE_PERL+=		lib/Devel/NYTProf/FileHandle.pm

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
