# $NetBSD: Makefile,v 1.1.1.1 2011/08/16 11:57:59 abs Exp $

DISTNAME=	Test-Fatal-0.006
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rjbs/Test-Fatal/
COMMENT=	Incredibly simple helpers for testing code with exceptions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Try-Tiny>=0.07:../../devel/p5-Try-Tiny

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=		auto/Test/Fatal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
