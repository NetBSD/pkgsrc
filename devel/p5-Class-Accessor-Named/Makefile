# $NetBSD: Makefile,v 1.12 2016/06/08 19:22:39 wiz Exp $

DISTNAME=	Class-Accessor-Named-0.009
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor-Named/
COMMENT=	Perl 5 module providing better profiling output for Class::Accessor
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Hook-LexWrap-[0-9]*:../../devel/p5-Hook-LexWrap
DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Class/Accessor/Named/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
