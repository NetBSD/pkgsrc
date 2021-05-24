# $NetBSD: Makefile,v 1.8 2021/05/24 19:50:37 wiz Exp $

DISTNAME=	ExtUtils-CChecker-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PEVANS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/ExtUtils::CChecker
COMMENT=	Perl5 configure-check utilities
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/ExtUtils/CChecker/.packlist
USE_LANGUAGES=		c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
