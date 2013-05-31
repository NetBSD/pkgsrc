# $NetBSD: Makefile,v 1.18 2013/05/31 12:40:43 wiz Exp $
#

DISTNAME=	Set-IntSpan-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5sis
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-IntSpan/
COMMENT=	Perl5 module for managing sets of integers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Set/IntSpan/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
