# $NetBSD: Makefile,v 1.19 2022/06/28 11:33:24 wiz Exp $

DISTNAME=	Test-Fatal-0.016
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Fatal
COMMENT=	Incredibly simple helpers for testing code with exceptions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Try-Tiny>=0.07:../../devel/p5-Try-Tiny

PERL5_PACKLIST=		auto/Test/Fatal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
