# $NetBSD: Makefile,v 1.1.1.1 2004/10/31 14:46:47 seb Exp $

DISTNAME=		Test-Pod-1.20
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tp
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		seb@NetBSD.org
COMMENT=		Perl5 module to check for POD errors in files

DEPENDS+=		p5-Pod-Simple-[0-9]*:../../textproc/p5-Pod-Simple
# These are only for the 'test' target.
BUILD_DEPENDS+=		p5-Test-Builder-Tester-[0-9]*:../../devel/p5-Test-Builder-Tester
BUILD_DEPENDS+=		p5-Pod-Escapes-[0-9]*:../../textproc/p5-Pod-Escapes

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
