# $NetBSD: Makefile,v 1.12 2011/08/12 08:24:55 adam Exp $

DISTNAME=	Devel-NYTProf-4.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/perl-devel-nytprof/
COMMENT=	Powerful feature-rich Perl 5 source code profiler
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.84}:../../devel/p5-Test-Simple
DEPENDS+=	p5-JSON-Any-[0-9]*:../../converters/p5-JSON-Any
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS

PERL5_PACKLIST=		auto/Devel/NYTProf/.packlist
REPLACE_PERL+=		lib/Devel/NYTProf/FileHandle.pm
REPLACE_PERL+=		perftest.pl

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
