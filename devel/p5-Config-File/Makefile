# $NetBSD: Makefile,v 1.5 2019/08/11 13:19:06 wiz Exp $

DISTNAME=	Config-File-1.51
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/T/TH/THESEAL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Config::File
COMMENT=	Parse a simple configuration file
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST=         auto/Config/File/.packlist
USE_LANGUAGES=          # none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
