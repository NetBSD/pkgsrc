# $NetBSD: Makefile,v 1.8 2012/10/03 21:54:45 wiz Exp $

DISTNAME=	Class-Std-0.011
PKGNAME=	p5-${DISTNAME:S/011/0.11/}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Std/
COMMENT=	Perl 5 module to support creation of standard inside-out classes
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Class/Std/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
