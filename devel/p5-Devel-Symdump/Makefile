# $NetBSD: Makefile,v 1.15 2005/02/19 12:45:49 wiz Exp $
#

DISTNAME=	Devel-Symdump-2.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dsd
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Symdump/
COMMENT=	Perl5 module for inspecting perl's symtable/class hiers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/Symdump/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
