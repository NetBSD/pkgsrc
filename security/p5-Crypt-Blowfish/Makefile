# $NetBSD: Makefile,v 1.17 2006/09/10 13:44:28 heinz Exp $
#

DISTNAME=		Crypt-Blowfish-2.10
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cbl
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Blowfish/
COMMENT=		Perl5 Blowfish implementation

BUILD_DEPENDS+=		p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CRYPTO=			YES
PERL5_PACKLIST=		auto/Crypt/Blowfish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
