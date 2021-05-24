# $NetBSD: Makefile,v 1.10 2021/05/24 19:54:14 wiz Exp $
#

DISTNAME=	Config-Simple-4.59
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SH/SHERZODR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Config-Simple
COMMENT=	Simple configuration file class
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Config/Simple/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
