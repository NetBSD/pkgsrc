# $NetBSD: Makefile,v 1.26 2022/06/28 11:32:30 wiz Exp $

DISTNAME=	Getopt-Euclid-0.4.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Getopt-Euclid
COMMENT=	Perl 5 module to create command-line parser from documentation
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.10.0,p5-version-[0-9]*}:../../devel/p5-version

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Getopt/Euclid/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
