# $NetBSD: Makefile,v 1.2 2023/07/06 09:40:02 wiz Exp $

DISTNAME=	String-Tagged-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

HOMEPAGE=	https://metacpan.org/release/String-Tagged
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl string buffers with value tags on extents
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

PERL5_PACKLIST=		auto/String/Tagged/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
