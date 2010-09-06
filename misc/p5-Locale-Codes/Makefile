# $NetBSD: Makefile,v 1.28 2010/09/06 11:08:25 wiz Exp $

DISTNAME=	Locale-Codes-3.13
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lco
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Locale-Codes/
COMMENT=	Perl5 module for ISO 3166, 639, 4217 and 15924 codes
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Locale/Codes/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
