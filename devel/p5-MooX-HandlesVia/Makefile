# $NetBSD: Makefile,v 1.9 2018/08/22 09:44:20 wiz Exp $

DISTNAME=	MooX-HandlesVia-0.001008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MATTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooX-HandlesVia/
COMMENT=	NativeTrait-like behavior for Moo
LICENSE=	gnu-gpl-v1 OR artistic

DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Data-Perl-[0-9]*:../../devel/p5-Data-Perl
DEPENDS+=	p5-MooX-Types-MooseLike-[0-9]*:../../devel/p5-MooX-Types-MooseLike

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=	auto/MooX/HandlesVia/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
