# $NetBSD: Makefile,v 1.23 2013/05/31 12:41:55 wiz Exp $
#

DISTNAME=		Crypt-Twofish-2.15
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5ctw
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Twofish/
COMMENT=		Perl5 module for the Twofish symmetric key algorithm
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_TOOLS+=		perl

PERL5_PACKLIST=		auto/Crypt/Twofish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
