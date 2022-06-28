# $NetBSD: Makefile,v 1.27 2022/06/28 11:33:35 wiz Exp $

DISTNAME=	UNIVERSAL-can-1.20140328
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=UNIVERSAL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/UNIVERSAL-can
COMMENT=	Hack around people calling UNIVERSAL::can() as a function
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=		{perl>=5.10,p5-Scalar-List-Utils>=0}:../../devel/p5-Scalar-List-Utils
#BUILD_DEPENDS+=	{perl>=5.10,p5-Test-Simple>=0.60}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
#PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/UNIVERSAL/can/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
