# $NetBSD: Makefile,v 1.4 2012/10/25 06:56:23 asau Exp $
#

DISTNAME=	Text-Brew-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Brew
COMMENT=	Perl module for configurable and analyzable edit distances
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Text/Brew/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
