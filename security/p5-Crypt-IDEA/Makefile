# $NetBSD: Makefile,v 1.30 2017/06/05 14:24:29 ryoon Exp $

DISTNAME=		Crypt-IDEA-1.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-IDEA/
COMMENT=		Perl5 module for the IDEA symmetric key algorithm
LICENSE=		original-bsd

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Crypt/IDEA/.packlist
REPLACE_PERL=		IDEA.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
