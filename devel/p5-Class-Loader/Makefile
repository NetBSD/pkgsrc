# $NetBSD: Makefile,v 1.16 2008/10/19 19:17:49 he Exp $
#

DISTNAME=		Class-Loader-2.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5clo
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		mcr@NetBSD.org
#	from sen_ml@eccosys.com
HOMEPAGE=		http://search.cpan.org/dist/Class-Loader/
COMMENT=		Perl5 module for module loading and on-demand object creation

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Class/Loader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
