# $NetBSD: Makefile,v 1.22 2021/04/28 07:36:39 wiz Exp $

DISTNAME=	CryptX-0.071
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/CryptX
COMMENT=	Crypto toolkit (self-contained no external libraries needed)
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/CryptX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
