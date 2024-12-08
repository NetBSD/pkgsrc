# $NetBSD: Makefile,v 1.45 2024/12/08 07:17:16 wiz Exp $

DISTNAME=		Crypt-DSA-1.19
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-DSA
COMMENT=		Perl5 module for the DSA public key algorithm
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Data-Buffer>=0.01:../../devel/p5-Data-Buffer
DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Convert-PEM>=0.13:../../textproc/p5-Convert-PEM
DEPENDS+=		p5-File-Which>=0.05:../../devel/p5-File-Which
DEPENDS+=		p5-Crypt-URandom>=0:../../security/p5-Crypt-URandom

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/DSA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
