# $NetBSD: Makefile,v 1.8 2017/06/05 14:22:51 ryoon Exp $

DISTNAME=	Devel-CheckCompiler-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-CheckCompiler/
COMMENT=	Check the compiler availability
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/Devel/CheckCompiler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
