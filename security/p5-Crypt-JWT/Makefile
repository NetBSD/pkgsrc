# $NetBSD: Makefile,v 1.5 2022/06/28 11:35:42 wiz Exp $

DISTNAME=		Crypt-JWT-0.034
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/Crypt::JWT
COMMENT=		Perl5 module for JSON Web Tokens
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=		p5-CryptX-[0-9]*:../../security/p5-CryptX

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/JWT/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
