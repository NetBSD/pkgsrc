# $NetBSD: Makefile,v 1.4 2010/08/31 05:28:21 sno Exp $

DISTNAME=	Devel-Leak-Object-1.01
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Devel::Devel::Leak
COMMENT=	perl module to detect leaks of objects
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= 	auto/Devel/Leak/Object/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
