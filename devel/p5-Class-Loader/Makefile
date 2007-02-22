# $NetBSD: Makefile,v 1.14 2007/02/22 11:50:33 wiz Exp $
#

DISTNAME=		Class-Loader-2.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5clo
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		mcr@NetBSD.org
#	from sen_ml@eccosys.com
HOMEPAGE=		http://search.cpan.org/dist/Class-Loader/
COMMENT=		Perl5 module for module loading and on-demand object creation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Class/Loader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
