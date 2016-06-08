# $NetBSD: Makefile,v 1.2 2016/06/08 19:23:31 wiz Exp $

DISTNAME=	String-Util-1.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
