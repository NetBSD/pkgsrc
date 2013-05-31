# $NetBSD: Makefile,v 1.14 2013/05/31 12:39:44 wiz Exp $

DISTNAME=	Convert-BinHex-1.119
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?query=convert+binhex
COMMENT=	Read and write Macintosh BinHex streams
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Convert/BinHex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
