# $NetBSD: Makefile,v 1.21 2004/12/20 11:31:03 grant Exp $

DISTNAME=		Test-Simple-0.47
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tsi
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		shell@NetBSD.org
COMMENT=		Perl5 module with a simple framework for writing tests

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Simple/.packlist

.include "../../devel/p5-Test-Harness/depends.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
