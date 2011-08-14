# $NetBSD: Makefile,v 1.17 2011/08/14 14:14:41 obache Exp $
#

DISTNAME=		IO-Socket-Multicast-1.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5ism
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Socket-Multicast/
COMMENT=		Perl multicast socket IO
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-IO-Interface>=0.94:../../net/p5-IO-Interface

PERL5_PACKLIST=		auto/IO/Socket/Multicast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
