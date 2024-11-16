# $NetBSD: Makefile,v 1.13 2024/11/16 12:06:29 wiz Exp $
#

DISTNAME=		Crypt-OpenSSL-Guess-0.15
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/akiym/Crypt-OpenSSL-Guess
COMMENT=		Guess OpenSSL include path
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Crypt/OpenSSL/Guess/.packlist

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_FILES.vars=	lib/Crypt/OpenSSL/Guess.pm
SUBST_VARS.vars=	BUILDLINK_PREFIX.openssl

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
