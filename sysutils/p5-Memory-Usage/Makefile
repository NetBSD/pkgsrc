# $NetBSD: Makefile,v 1.1 2026/10/04 09:54:12 wiz Exp $

DISTNAME=	Memory-Usage-0.201
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DO/DONEILL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Memory::Usage
COMMENT=	Tools to determine actual memory usage
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Install

PERL5_PACKLIST=	auto/Memory/Usage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
