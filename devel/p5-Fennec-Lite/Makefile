# $NetBSD: Makefile,v 1.5 2024/11/16 12:04:13 wiz Exp $

DISTNAME=	Fennec-Lite-0.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Fennec::Lite
COMMENT=	Minimalist Fennec, the commonly used bits
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Fennec/Lite/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
