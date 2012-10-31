# $NetBSD: Makefile,v 1.6 2012/10/31 11:18:18 asau Exp $
#

DISTNAME=	Hash-MoreUtils-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Hash-MoreUtils/
COMMENT=	Perl 5 module provides the stuff missing in Hash::Util
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty

PERL5_PACKLIST=		auto/Hash/MoreUtils/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
