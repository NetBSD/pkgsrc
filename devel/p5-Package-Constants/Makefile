# $NetBSD: Makefile,v 1.22 2025/07/04 08:46:23 wiz Exp $
#

DISTNAME=	Package-Constants-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Package/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Package-Constants
COMMENT=	Lists all the constants defined in a Perl package
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Package/Constants/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
