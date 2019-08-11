# $NetBSD: Makefile,v 1.18 2019/08/11 13:19:03 wiz Exp $

DISTNAME=	Class-Std-0.013
PKGNAME=	p5-${DISTNAME:S/013/0.13/}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Std
COMMENT=	Perl 5 module to support creation of standard inside-out classes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Std/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
