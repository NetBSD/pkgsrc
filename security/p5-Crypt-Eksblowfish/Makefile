# $NetBSD: Makefile,v 1.2 2009/05/03 06:41:23 seb Exp $
#

DISTNAME=		Crypt-Eksblowfish-0.007
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Eksblowfish/
COMMENT=		Perl5 Eksblowfish block cipher

DEPENDS+=		p5-Class-Mix>=0.001:../../devel/p5-Class-Mix
DEPENDS+=		p5-parent-[0-9]*:../../devel/p5-parent
DEPENDS+=		p5-MIME-Base64>=2.21:../../converters/p5-MIME-Base64
BUILD_DEPENDS+=		p5-ExtUtils-CBuilder>=0.15:../../devel/p5-ExtUtils-CBuilder

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

CRYPTO=			YES
USE_LANGUAGES=		c
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Crypt/Eksblowfish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
