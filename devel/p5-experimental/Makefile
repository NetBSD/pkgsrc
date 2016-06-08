# $NetBSD: Makefile,v 1.7 2016/06/08 19:23:47 wiz Exp $

DISTNAME=	experimental-0.013
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LE/LEONT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/experimental/
COMMENT=	Replace functions with ones that succeed or die with lexical scope
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/experimental/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
