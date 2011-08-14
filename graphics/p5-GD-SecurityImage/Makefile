# $NetBSD: Makefile,v 1.4 2011/08/14 12:59:49 obache Exp $
#

DISTNAME=	GD-SecurityImage-1.70
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5gsi
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 security image (CAPTCHA) generator
HOMEPAGE=	http://search.cpan.org/dist/GD-SecurityImage/
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-GD>0:../../graphics/p5-GD
DEPENDS+=	p5-PerlMagick>=6.0.4:../../graphics/p5-PerlMagick

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/GD/SecurityImage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
