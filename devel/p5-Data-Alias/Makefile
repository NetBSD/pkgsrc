# $NetBSD: Makefile,v 1.24 2019/06/30 20:14:47 nia Exp $

DISTNAME=	Data-Alias-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Alias
COMMENT=	Comprehensive set of aliasing operations
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Data/Alias/.packlist
PERL5_MODULE_TYPE=	Module::Install

USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
