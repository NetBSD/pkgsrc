# $NetBSD: Makefile,v 1.25 2013/07/14 06:32:07 wen Exp $

DISTNAME=	Digest-MD4-1.9
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5md4
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-MD4/
COMMENT=	Perl5 module for MD4 hash algorithm
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Digest/MD4/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
