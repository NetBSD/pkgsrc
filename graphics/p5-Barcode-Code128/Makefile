# $NetBSD: Makefile,v 1.1.1.1 2011/02/26 18:27:00 abs Exp $

DISTNAME=		Barcode-Code128-2.01
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Barcode/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~wrw/Barcode-Code128-2.01
COMMENT=		Generates bar codes using the CODE 128 symbology

PKG_DESTDIR_SUPPORT=	user-destdir
LICENSE=		public-domain

DEPENDS+=		p5-GD>=1.18:../../graphics/p5-GD

PERL5_PACKLIST=	auto/Barcode/Code128/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
