# $NetBSD: Makefile,v 1.31 2017/06/05 14:24:31 ryoon Exp $

DISTNAME=		Crypt-Twofish-2.17
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Twofish/
COMMENT=		Perl5 module for the Twofish symmetric key algorithm
LICENSE=		${PERL5_LICENSE}

USE_TOOLS+=		perl

PERL5_PACKLIST=		auto/Crypt/Twofish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
