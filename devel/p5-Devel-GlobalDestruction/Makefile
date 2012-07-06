# $NetBSD: Makefile,v 1.6 2012/07/06 10:06:55 sno Exp $

DISTNAME=	Devel-GlobalDestruction-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-GlobalDestruction/
COMMENT=	Perl 5 package exposing the flag which marks global destruction

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-Scope-Guard-[0-9]*:../../devel/p5-Scope-Guard
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Devel/GlobalDestruction/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
