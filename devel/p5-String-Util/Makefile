# $NetBSD: Makefile,v 1.3 2016/09/19 09:07:38 mef Exp $

DISTNAME=	String-Util-1.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/M/MI/MIKO/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/M/MI/MIKO/
COMMENT=	String processing utilities
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Test-Toolbox-[0-9]*:../../devel/p5-Test-Toolbox

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/String/Util/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
