# $NetBSD: Makefile,v 1.2 2018/08/22 09:44:41 wiz Exp $

DISTNAME=	Taint-Util-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/A/AV/AVAR/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/A/AV/AVAR/
COMMENT=	Perl5 test for and flip the taint flag without regex matches or eval
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XSLoader>=0:../../devel/p5-XSLoader

PERL5_PACKLIST=	auto/Taint/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
