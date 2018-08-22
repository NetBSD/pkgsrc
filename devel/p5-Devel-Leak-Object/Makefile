# $NetBSD: Makefile,v 1.14 2018/08/22 09:43:54 wiz Exp $

DISTNAME=	Devel-Leak-Object-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Leak-Object/
COMMENT=	Perl module to detect leaks of objects
LICENSE=	${PERL5_LICENSE}

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Devel/Leak/Object/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
