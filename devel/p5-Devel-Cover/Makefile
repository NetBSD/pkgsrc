# $NetBSD: Makefile,v 1.1.1.1 2008/09/14 18:00:54 seb Exp $
#

DISTNAME=	Devel-Cover-0.64
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Cover/
COMMENT=	Perl 5 module providing code coverage metrics

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Devel/Cover/.packlist

DEPENDS+=	p5-PPI-HTML>=1.07:../../textproc/p5-PPI-HTML
DEPENDS+=	p5-Perl-Tidy>=20060719:../../devel/p5-Perl-Tidy
DEPENDS+=	p5-Pod-Coverage>=0.06:../../textproc/p5-Pod-Coverage
DEPENDS+=	p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
