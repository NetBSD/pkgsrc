# $NetBSD: Makefile,v 1.11 2022/06/28 11:32:14 wiz Exp $

DISTNAME=	Debug-ShowStuff-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIKO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Debug::ShowStuff
COMMENT=	Collection of handy debugging routines to display values of variables
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-String-Util-[0-9]*:../../devel/p5-String-Util
BUILD_DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Debug/ShowStuff/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
