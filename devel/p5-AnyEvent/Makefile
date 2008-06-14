# $NetBSD: Makefile,v 1.5 2008/06/14 20:57:34 heinz Exp $
#

DISTNAME=	AnyEvent-2.9
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.cpan.org/modules/by-authors/Marc_Lehmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/AnyEvent.html
COMMENT=	Simple API for io, timer and completion callbacks

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-glib2-[0-9]*:../../devel/p5-glib2

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/AnyEvent/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
