# $NetBSD: Makefile,v 1.2 2012/10/03 21:55:40 wiz Exp $
#

DISTNAME=	Test-CheckDeps-0.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-CheckDeps/
COMMENT=	Perl 5 module to check for presence of dependencies
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.14.0,p5-CPAN-Meta-[0-9]*}:../../devel/p5-CPAN-Meta
DEPENDS+=	p5-CPAN-Meta-Check-[0-9]*:../../devel/p5-CPAN-Meta-Check

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/CheckDeps/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
