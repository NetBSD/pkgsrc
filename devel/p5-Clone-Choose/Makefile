# $NetBSD: Makefile,v 1.2 2018/04/10 00:42:40 wen Exp $

DISTNAME=	Clone-Choose-0.010
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/H/HE/HERMES/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Clone-Choose/
COMMENT=	Perl5 module to choose appropriate clone utility
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
BUILD_DEPENDS+=	p5-Clone-PP-[0-9]*:../../devel/p5-Clone-PP

PERL5_PACKLIST=		auto/Clone/Choose/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
