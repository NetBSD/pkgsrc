# $NetBSD: Makefile,v 1.3 2008/11/17 22:55:37 he Exp $

DISTNAME=	Locale-Currency-Format-1.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TN/TNGUYEN/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Locale-Currency-Format/
COMMENT=	Perl functions for formatting monetary values

DEPENDS+=       p5-Locale-Codes>=2.07:../../misc/p5-Locale-Codes

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Locale/Currency/Format/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
