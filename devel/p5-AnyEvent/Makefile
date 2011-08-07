# $NetBSD: Makefile,v 1.22 2011/08/07 06:05:31 adam Exp $

DISTNAME=	AnyEvent-5.34
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
#MASTER_SITES=	http://www.cpan.org/modules/by-authors/Marc_Lehmann/
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/AnyEvent.html
COMMENT=	Simple API for io, timer and completion callbacks
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=	auto/AnyEvent/.packlist

# recommented dependencies:
DEPENDS+=	p5-Async-Interrupt>=1:../../devel/p5-Async-Interrupt
DEPENDS+=	p5-EV>=3.1:../../devel/p5-EV
DEPENDS+=	p5-Guard>=1.020:../../devel/p5-Guard
DEPENDS+=	p5-JSON>=2.09:../../converters/p5-JSON
DEPENDS+=	p5-JSON-XS>=2.200:../../converters/p5-JSON-XS
DEPENDS+=	p5-Net-SSLeay>=1.33:../../security/p5-Net-SSLeay

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
