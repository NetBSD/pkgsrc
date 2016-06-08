# $NetBSD: Makefile,v 1.22 2016/06/08 19:22:47 wiz Exp $

DISTNAME=	Date-Business-1.2
PKGNAME=	${DISTNAME:S/Date-Business/p5-Date-Business/}
PKGREVISION=	10
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cpan.org/
COMMENT=	Perl5 module for fast calendar and business date calculations
LICENSE=	morganstanley-license

PERL5_PACKLIST=		auto/Date/Business/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
