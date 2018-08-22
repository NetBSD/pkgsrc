# $NetBSD: Makefile,v 1.2 2018/08/22 09:43:58 wiz Exp $

DISTNAME=	ExtUtils-CChecker-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/P/PE/PEVANS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/P/PE/PEVANS/
COMMENT=	Perl5 configure-check utilities
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/ExtUtils/CChecker/.packlist
USE_LANGUAGES=		c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
