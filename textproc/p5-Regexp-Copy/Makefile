# $NetBSD: Makefile,v 1.4 2012/10/03 21:57:58 wiz Exp $
#

DISTNAME=		Regexp-Copy-0.06
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Regexp-Copy/
COMMENT=		Perl5 module to copy Regexp objects
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Regexp/Copy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
