# $NetBSD: Makefile,v 1.19 2004/05/07 11:30:39 grant Exp $

DISTNAME=		Test-Simple-0.47
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tsi
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		shell@NetBSD.org
COMMENT=		Perl5 module with a simple framework for writing tests

# gah. perl58>=5.8.3 includes Test::Harness, so allow it to satisfy
# this dependency.
DEPENDS+=		{p5-Test-Harness-[0-9]*,perl{,-thread}>=5.8.3}:../../devel/p5-Test-Harness

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
