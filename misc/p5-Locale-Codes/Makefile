# $NetBSD: Makefile,v 1.34 2013/12/02 12:17:17 wiz Exp $

DISTNAME=	Locale-Codes-3.27
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lco
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Locale-Codes/
COMMENT=	Perl5 module for ISO 3166, 639, 4217 and 15924 codes
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Locale/Codes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
