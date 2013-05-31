# $NetBSD: Makefile,v 1.7 2013/05/31 12:40:39 wiz Exp $
#

DISTNAME=	Perl-APIReference-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Perl-APIReference/
COMMENT=	Programmatically query the perlapi
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

DEPENDS+=	p5-Class-XSAccessor>=1.05:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-YAML-Tiny-[0-9]*:../../textproc/p5-YAML-Tiny
DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent

PERL5_PACKLIST=		auto/Perl/APIReference/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
