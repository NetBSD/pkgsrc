# $NetBSD: Makefile,v 1.6 2013/12/09 14:17:45 obache Exp $
#

DISTNAME=	Log-Handler-0.76
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Handler/
COMMENT=	Log messages to several outputs
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Config-General>=0:../../devel/p5-Config-General
DEPENDS+=	p5-Config-Properties>=0:../../devel/p5-Config-Properties
DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI
DEPENDS+=	p5-Email-Date>=0:../../mail/p5-Email-Date
DEPENDS+=	p5-PathTools>=0:../../devel/p5-PathTools
DEPENDS+=	p5-Params-Validate>=0:../../devel/p5-Params-Validate
DEPENDS+=	{perl>=5.6.2,p5-Test-Simple>=0}:../../devel/p5-Test-Simple
DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes>=0}:../../time/p5-Time-HiRes
DEPENDS+=	p5-YAML>=0:../../textproc/p5-YAML

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Log/Handler/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
