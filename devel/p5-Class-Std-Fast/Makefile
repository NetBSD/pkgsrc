# $NetBSD: Makefile,v 1.1 2023/06/09 19:34:48 gdt Exp $

DISTNAME=	Class-Std-Fast-v0.0.8
PKGNAME=	p5-${DISTNAME:S,-v,-,}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AC/ACID/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Std::Fast
COMMENT=	Faster but less secure than Class::Std
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Std/Fast/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
