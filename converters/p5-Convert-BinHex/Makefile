# $NetBSD: Makefile,v 1.10 2010/08/21 16:32:48 seb Exp $

DISTNAME=		Convert-BinHex-1.119
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/search?query=convert+binhex
COMMENT=		Read and write Macintosh BinHex streams

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Convert/BinHex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
