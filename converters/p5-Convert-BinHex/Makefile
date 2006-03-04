# $NetBSD: Makefile,v 1.7 2006/03/04 21:29:06 jlam Exp $

DISTNAME=		Convert-BinHex-1.119
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/search?query=convert+binhex
COMMENT=		Read and write Macintosh BinHex streams

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Convert/BinHex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
