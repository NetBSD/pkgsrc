# $NetBSD: Makefile,v 1.1 2015/11/26 14:14:59 mef Exp $

DISTNAME=	String-Util-1.24
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/M/MI/MIKO/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/M/MI/MIKO/
COMMENT=	String processing utilities
LICENSE=	${PERL5_LICENSE}

# TODO: Look for the dependencies in Build.PL.

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/String/Util/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
