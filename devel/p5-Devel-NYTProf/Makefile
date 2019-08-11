# $NetBSD: Makefile,v 1.33 2019/08/11 13:19:17 wiz Exp $

DISTNAME=	Devel-NYTProf-6.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-NYTProf
COMMENT=	Powerful feature-rich Perl 5 source code profiler
LICENSE=	${PERL5_LICENSE}

#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.84}:../../devel/p5-Test-Simple
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
BUILD_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
BUILD_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PERL5_PACKLIST=		auto/Devel/NYTProf/.packlist
REPLACE_PERL+=		lib/Devel/NYTProf/FileHandle.pm

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
