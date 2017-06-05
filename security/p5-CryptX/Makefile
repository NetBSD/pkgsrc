# $NetBSD: Makefile,v 1.2 2017/06/05 14:24:31 ryoon Exp $

DISTNAME=	CryptX-0.047
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MI/MIK/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MI/MIK/
COMMENT=	Crypto toolkit (self-contained no external libraries needed)
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/CryptX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
