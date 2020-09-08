# $NetBSD: Makefile,v 1.20 2020/09/08 13:09:58 wiz Exp $

DISTNAME=	CryptX-0.069
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/M/MI/MIK/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/CryptX
COMMENT=	Crypto toolkit (self-contained no external libraries needed)
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/CryptX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
