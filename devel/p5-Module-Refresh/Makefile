# $NetBSD: Makefile,v 1.26 2023/07/06 09:39:34 wiz Exp $

DISTNAME=	Module-Refresh-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Refresh
COMMENT=	Perl5 module providing %INC files refreshing when updated on disk
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class

PERL5_PACKLIST=		auto/Module/Refresh/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
