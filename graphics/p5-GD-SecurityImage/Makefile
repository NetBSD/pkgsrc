# $NetBSD: Makefile,v 1.1.1.1 2008/11/17 21:05:54 he Exp $
#

DISTNAME=	GD-SecurityImage-1.66
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5gsi
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 security image (CAPTCHA) generator

DEPENDS+=	p5-GD>0:../../graphics/p5-GD
DEPENDS+=	p5-PerlMagick>=6.0.4:../../graphics/p5-PerlMagick

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/GD/SecurityImage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
