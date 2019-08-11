# $NetBSD: Makefile,v 1.21 2019/08/11 13:20:48 wiz Exp $

DISTNAME=	signatures-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/signatures
COMMENT=	Subroutine signatures with no source filter
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/signatures/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled

BUILD_DEPENDS+=    p5-ExtUtils-Depends>=0.302:../../devel/p5-ExtUtils-Depends

DEPENDS+=	p5-B-Hooks-EndOfScope>=0.08:../../devel/p5-B-Hooks-EndOfScope

BUILDLINK_API_DEPENDS.p5-B-Hooks-OP-Check+=	p5-B-Hooks-OP-Check>=0.17
BUILDLINK_API_DEPENDS.p5-B-Hooks-Parser+=	p5-B-Hooks-Parser>=0.07

.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../devel/p5-B-Hooks-OP-PPAddr/buildlink3.mk"
.include "../../devel/p5-B-Hooks-Parser/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
