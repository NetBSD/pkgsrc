# $NetBSD: Makefile,v 1.17 2004/03/31 01:52:04 jlam Exp $

DISTNAME=		Test-Harness-2.40
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tha
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		shell@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Harness/
COMMENT=		Perl5 module for testing

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Harness/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
