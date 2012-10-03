# $NetBSD: Makefile,v 1.9 2012/10/03 21:56:03 wiz Exp $

DISTNAME=	Locale-Currency-Format-1.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TN/TNGUYEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Locale-Currency-Format/
COMMENT=	Perl functions for formatting monetary values
LICENSE=	gnu-gpl-v2 # OR artistic

#DEPENDS+=       p5-Locale-Codes>=2.07:../../misc/p5-Locale-Codes

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Locale/Currency/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
