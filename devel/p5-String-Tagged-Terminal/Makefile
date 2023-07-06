# $NetBSD: Makefile,v 1.2 2023/07/06 09:40:02 wiz Exp $

DISTNAME=	String-Tagged-Terminal-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

HOMEPAGE=	https://metacpan.org/release/String-Tagged-Terminal
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Format terminal output using String::Tagged
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Convert-Color-[0-9]*:../../converters/p5-Convert-Color
DEPENDS+=	p5-Convert-Color-XTerm-[0-9]*:../../converters/p5-Convert-Color-XTerm
DEPENDS+=	p5-String-Tagged-[0-9]*:../../devel/p5-String-Tagged
TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

PERL5_PACKLIST=		auto/String/Tagged/Terminal/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
