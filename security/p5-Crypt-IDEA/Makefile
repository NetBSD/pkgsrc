# $NetBSD: Makefile,v 1.25 2014/05/29 23:37:22 wiz Exp $

DISTNAME=		Crypt-IDEA-1.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-IDEA/
COMMENT=		Perl5 module for the IDEA symmetric key algorithm
LICENSE=		idea-license

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Crypt/IDEA/.packlist
REPLACE_PERL=		IDEA.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
