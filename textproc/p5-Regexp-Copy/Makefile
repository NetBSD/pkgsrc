# $NetBSD: Makefile,v 1.7 2014/05/29 23:37:39 wiz Exp $
#

DISTNAME=		Regexp-Copy-0.06
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Regexp-Copy/
COMMENT=		Perl5 module to copy Regexp objects
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Regexp/Copy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
