# $NetBSD: Makefile,v 1.32 2014/09/06 12:12:00 wiz Exp $

DISTNAME=	Devel-Symdump-2.12
PKGNAME=	p5-${DISTNAME}00
SVR4_PKGNAME=	p5dsd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Symdump/
COMMENT=	Perl5 module for inspecting perl's symtable/class hiers
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Devel/Symdump/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
