# $NetBSD: Makefile,v 1.12 2019/09/02 12:34:28 adam Exp $

DISTNAME=	Class-DBI-BaseDSN-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-DBI-BaseDSN
COMMENT=	DSN sensitive base class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-DBI-[0-9]*:../../databases/p5-Class-DBI
#DEPENDS+=	{perl>=5.6.2,p5-Test-Simple-[0-9]*}:../../devel/p5-Test-Simple

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Class/DBI/BaseDSN/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
