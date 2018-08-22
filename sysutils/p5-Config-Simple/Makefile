# $NetBSD: Makefile,v 1.6 2018/08/22 09:46:36 wiz Exp $
#

DISTNAME=	Config-Simple-4.59
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SH/SHERZODR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Simple/
COMMENT=	Simple configuration file class
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Config/Simple/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
