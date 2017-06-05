# $NetBSD: Makefile,v 1.24 2017/06/05 14:23:25 ryoon Exp $

DISTNAME=	PPI-1.220
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PPI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PPI/
COMMENT=	Perl 5 module to parse, analyze and manipulate Perl (without perl)
LICENSE=	${PERL5_LICENSE}

# Before update this package, please check $XS_COMPATIBLE in lib/PPI.pm.
# If it is greater than version of devel/p5-PPI-XS, p5-PPI-XS should be updated.
DEPENDS+=	p5-Clone>=0.30:../../devel/p5-Clone
#DEPENDS+=	{perl>=5.10,p5-Digest-MD5>=2.35}:../../security/p5-Digest-MD5
DEPENDS+=	p5-IO-String>=1.07:../../devel/p5-IO-String
DEPENDS+=	p5-List-MoreUtils>=0.16:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Params-Util>=1.00:../../devel/p5-Params-Util
#DEPENDS+=	{perl>=5.10.1,p5-Scalar-List-Utils>=1.20}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
#DEPENDS+=	{perl>=5.8,p5-Storable>=2.17}:../../devel/p5-Storable

BUILD_DEPENDS+=	p5-Class-Inspector>=1.22:../../devel/p5-Class-Inspector
BUILD_DEPENDS+=	p5-File-Remove>=1.42:../../sysutils/p5-File-Remove
BUILD_DEPENDS+=	p5-Test-NoWarnings>=0.084:../../devel/p5-Test-NoWarnings
BUILD_DEPENDS+=	p5-Test-Object>=0.07:../../devel/p5-Test-Object
#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.86}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-SubCalls>=1.07:../../devel/p5-Test-SubCalls

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PPI/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
