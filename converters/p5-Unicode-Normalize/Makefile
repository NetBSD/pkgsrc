# $NetBSD: Makefile,v 1.1.1.1 2012/02/12 18:40:42 abs Exp $

DISTNAME=		Unicode-Normalize-1.13
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~sadahiro/Unicode-Normalize
COMMENT=		Unicode Normalization Froms

LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		c

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Unicode/Normalize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
