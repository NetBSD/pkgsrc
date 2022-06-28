# $NetBSD: Makefile,v 1.25 2022/06/28 11:32:58 wiz Exp $

DISTNAME=	Object-Signature-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Object-Signature
COMMENT=	Generate cryptographic signatures for objects
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	p5-Storable>=2.11:../../devel/p5-Storable
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5>=2.00}:../../security/p5-Digest-MD5
#DEPENDS+=	{perl>=5.8.1,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
DEPENDS+=	p5-PathTools>=0.80:../../devel/p5-PathTools
DEPENDS+=	p5-ExtUtils-AutoInstall>=0.63:../../devel/p5-ExtUtils-AutoInstall

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Object/Signature/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
