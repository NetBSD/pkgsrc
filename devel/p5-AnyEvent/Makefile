# $NetBSD: Makefile,v 1.2 2007/04/14 18:38:57 xtraeme Exp $
#

DISTNAME=	AnyEvent-2.52
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.cpan.org/modules/by-authors/Marc_Lehmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/AnyEvent.html
COMMENT=	Simple API for io, timer and completion callbacks

DEPENDS+=	p5-glib2-[0-9]*:../../devel/p5-glib2

PERL5_PACKLIST=	auto/AnyEvent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
