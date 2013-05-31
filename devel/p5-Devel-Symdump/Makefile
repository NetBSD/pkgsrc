# $NetBSD: Makefile,v 1.29 2013/05/31 12:40:16 wiz Exp $

DISTNAME=	Devel-Symdump-2.08
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	5
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
