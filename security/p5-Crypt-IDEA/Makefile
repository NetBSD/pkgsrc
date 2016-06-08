# $NetBSD: Makefile,v 1.28 2016/06/08 19:24:20 wiz Exp $

DISTNAME=		Crypt-IDEA-1.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-IDEA/
COMMENT=		Perl5 module for the IDEA symmetric key algorithm
LICENSE=		idea-license

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Crypt/IDEA/.packlist
REPLACE_PERL=		IDEA.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
