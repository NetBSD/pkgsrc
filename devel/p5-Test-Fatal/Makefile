# $NetBSD: Makefile,v 1.7 2013/12/04 14:03:52 adam Exp $

DISTNAME=	Test-Fatal-0.013
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rjbs/Test-Fatal/
COMMENT=	Incredibly simple helpers for testing code with exceptions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Try-Tiny>=0.07:../../devel/p5-Try-Tiny

PERL5_PACKLIST=		auto/Test/Fatal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
