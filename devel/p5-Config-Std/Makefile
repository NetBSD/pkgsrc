# $NetBSD: Makefile,v 1.25 2023/07/06 09:38:52 wiz Exp $

DISTNAME=	Config-Std-0.903
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BR/BRICKER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Config-Std
COMMENT=	Perl 5 module providing a simple configuration-file system
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Std-[0-9]*:../../devel/p5-Class-Std
#DEPENDS+=	{perl>=5.9.0,p5-version-[0-9]*}:../../devel/p5-version

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Config/Std/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
