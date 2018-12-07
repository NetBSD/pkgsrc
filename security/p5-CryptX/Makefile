# $NetBSD: Makefile,v 1.14 2018/12/07 12:06:16 wen Exp $

DISTNAME=	CryptX-0.063
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
