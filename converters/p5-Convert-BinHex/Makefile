# $NetBSD: Makefile,v 1.18 2014/10/09 14:06:04 wiz Exp $

DISTNAME=	Convert-BinHex-1.123
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?query=convert+binhex
COMMENT=	Read and write Macintosh BinHex streams
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Convert/BinHex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
