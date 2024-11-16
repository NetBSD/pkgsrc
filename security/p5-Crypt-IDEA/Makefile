# $NetBSD: Makefile,v 1.38 2024/11/16 12:06:28 wiz Exp $

DISTNAME=		Crypt-IDEA-1.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-IDEA
COMMENT=		Perl5 module for the IDEA symmetric key algorithm
LICENSE=		original-bsd

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Crypt/IDEA/.packlist
REPLACE_PERL=		IDEA.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
