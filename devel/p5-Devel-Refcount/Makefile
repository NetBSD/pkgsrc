# $NetBSD: Makefile,v 1.7 2019/08/11 13:19:18 wiz Exp $

DISTNAME=	Devel-Refcount-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Refcount
COMMENT=	Perl 5 module to obtain the REFCNT value of a referent
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Devel/Refcount/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
