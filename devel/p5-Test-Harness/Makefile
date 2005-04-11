# $NetBSD: Makefile,v 1.22 2005/04/11 21:45:35 tv Exp $

DISTNAME=		Test-Harness-2.40
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tha
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		shell@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Harness/
COMMENT=		Perl5 module for testing

CONFLICTS+=		perl>=5.8.3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Harness/.packlist

BUILDLINK_PKGSRCDIR.perl=	../../lang/perl5

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
