# $NetBSD: Makefile,v 1.13 2018/11/10 08:40:57 wen Exp $

DISTNAME=	CryptX-0.062
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MI/MIK/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MI/MIK/
COMMENT=	Crypto toolkit (self-contained no external libraries needed)
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/CryptX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
