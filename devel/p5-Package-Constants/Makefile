# $NetBSD: Makefile,v 1.6 2013/03/02 10:44:34 tron Exp $
#

DISTNAME=	Package-Constants-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Package/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Package-Constants/
COMMENT=	Lists all the constants defined in a Perl package
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Package/Constants/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
