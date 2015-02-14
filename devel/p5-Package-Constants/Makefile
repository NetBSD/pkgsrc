# $NetBSD: Makefile,v 1.10 2015/02/14 02:44:15 mef Exp $
#

DISTNAME=	Package-Constants-0.06
PKGNAME=	p5-${DISTNAME}
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
