# $NetBSD: Makefile,v 1.15 2019/06/30 20:14:35 nia Exp $

DISTNAME=	CPAN-Inject-1.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN-Inject
COMMENT=	Inject a distribution for installation via the CPAN shell
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CPAN-Checksums>=1.05:../../devel/p5-CPAN-Checksums
DEPENDS+=	p5-File-chmod>=0.30:../../sysutils/p5-File-chmod
DEPENDS+=	p5-Params-Util>=0.21:../../devel/p5-Params-Util
BUILD_DEPENDS+=	p5-File-Remove>=0.38:../../sysutils/p5-File-Remove
BUILD_DEPENDS+=	p5-Test-Script>=1.02:../../devel/p5-Test-Script

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CPAN/Inject/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
