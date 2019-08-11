# $NetBSD: Makefile,v 1.4 2019/08/11 13:20:23 wiz Exp $

DISTNAME=	Taint-Util-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://cpan.metacpan.org/authors/id/A/AV/AVAR/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/A/AV/AVAR/
COMMENT=	Perl5 test for and flip the taint flag without regex matches or eval
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XSLoader>=0:../../devel/p5-XSLoader

PERL5_PACKLIST=	auto/Taint/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
