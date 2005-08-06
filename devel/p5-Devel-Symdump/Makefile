# $NetBSD: Makefile,v 1.18 2005/08/06 06:19:10 jlam Exp $
#

DISTNAME=	Devel-Symdump-2.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dsd
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Symdump/
COMMENT=	Perl5 module for inspecting perl's symtable/class hiers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Devel/Symdump/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
