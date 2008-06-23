# $NetBSD: Makefile,v 1.1.1.1 2008/06/23 01:59:42 abs Exp $

DISTNAME=	Locale-Currency-Format-1.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TN/TNGUYEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Locale::Currency::Format
COMMENT=	Perl functions for formatting monetary values

DEPENDS+=       p5-Locale-Codes>=2.07:../../misc/p5-Locale-Codes

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Locale/Currency/Format/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
