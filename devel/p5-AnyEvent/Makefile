# $NetBSD: Makefile,v 1.3 2008/02/20 10:57:21 xtraeme Exp $
#

DISTNAME=	AnyEvent-2.9
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
