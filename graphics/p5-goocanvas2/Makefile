# $NetBSD: Makefile,v 1.6 2023/01/29 21:14:43 ryoon Exp $

DISTNAME=	GooCanvas2-0.06
PKGNAME=	p5-${DISTNAME:S/GooCanvas/goocanvas/}
PKGREVISION=	5
CATEGORIES=	graphics perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/P/PE/PERLMAX/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/GooCanvas2
COMMENT=	Perl bindings for goocanvas2

.include "../../lang/perl5/license.mk"
LICENSE=	${PERL5_LICENSE}


PERL5_PACKLIST=	auto/GooCanvas2/.packlist
USE_LANGUAGES=	# none

.include "../../graphics/goocanvas2/buildlink3.mk"
.include "../../x11/p5-gtk3/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
