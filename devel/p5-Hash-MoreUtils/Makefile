# $NetBSD: Makefile,v 1.19 2021/05/24 19:50:49 wiz Exp $
#

DISTNAME=	Hash-MoreUtils-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Hash-MoreUtils
COMMENT=	Provide the stuff missing in Hash::Util
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Hash/MoreUtils/.packlist
#PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
