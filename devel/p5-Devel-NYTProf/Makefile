# $NetBSD: Makefile,v 1.6 2010/03/08 14:38:52 sno Exp $
#

DISTNAME=	Devel-NYTProf-3.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-NYTProf/
COMMENT=	Powerful feature-rich Perl 5 source code profiler
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=	perftest.pl lib/Devel/NYTProf/FileHandle.pm

DEPENDS+=	p5-JSON-Any-[0-9]*:../../converters/p5-JSON-Any
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.84}:../../devel/p5-Test-Simple

.include "options.mk"

PERL5_PACKLIST=	auto/Devel/NYTProf/.packlist

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
