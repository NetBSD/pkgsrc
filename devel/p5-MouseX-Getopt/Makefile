# $NetBSD: Makefile,v 1.17 2023/07/06 09:39:43 wiz Exp $

DISTNAME=	MouseX-Getopt-0.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MouseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MouseX-Getopt
COMMENT=	Mouse role for processing command line options
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MouseX/Getopt/.packlist

DEPENDS+=	p5-Mouse>=0.64:../../devel/p5-Mouse
DEPENDS+=	p5-Getopt-Long-Descriptive>=0.091:../../devel/p5-Getopt-Long-Descriptive

TOOL_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception

PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
