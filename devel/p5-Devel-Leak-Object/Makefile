# $NetBSD: Makefile,v 1.2 2009/10/24 16:25:43 sno Exp $

DISTNAME=	Devel-Leak-Object-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Devel::Devel::Leak
COMMENT=	perl module to detect leaks of objects
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= 	auto/Devel/Leak/Object/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled
MAKE_PARAMS+=		--skipdeps

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
