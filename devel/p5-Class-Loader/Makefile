# $NetBSD: Makefile,v 1.11 2005/04/20 16:36:46 heinz Exp $
#

DISTNAME=		Class-Loader-2.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5clo
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		mcr@NetBSD.org
#	from sen_ml@eccosys.com
HOMEPAGE=		http://search.cpan.org/dist/Class-Loader/
COMMENT=		Perl5 module for module loading and on-demand object creation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/Loader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
