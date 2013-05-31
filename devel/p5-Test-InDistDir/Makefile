# $NetBSD: Makefile,v 1.4 2013/05/31 12:40:48 wiz Exp $

DISTNAME=		Test-InDistDir-1.112071
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-InDistDir/
COMMENT=		Test environment setup for development with IDE
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/InDistDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
