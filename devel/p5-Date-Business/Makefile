# $NetBSD: Makefile,v 1.25 2018/08/22 09:43:52 wiz Exp $

DISTNAME=	Date-Business-1.2
PKGNAME=	${DISTNAME:S/Date-Business/p5-Date-Business/}
PKGREVISION=	12
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~desiminer/Date-Business/
COMMENT=	Perl5 module for fast calendar and business date calculations
LICENSE=	morganstanley-license

PERL5_PACKLIST=		auto/Date/Business/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
