# $NetBSD: Makefile,v 1.3 2024/01/01 09:11:18 mef Exp $

DISTNAME=	String-Tagged-0.22
PKGNAME=	p5-${DISTNAME}
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
