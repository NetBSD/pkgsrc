# $NetBSD: Makefile,v 1.3 2012/10/03 21:56:11 wiz Exp $

DISTNAME=	Barcode-Code128-2.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/W/WR/WRW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Barcode-Code128
COMMENT=	Generate CODE 128 bar codes
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Barcode/Code128/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
