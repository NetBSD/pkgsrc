# $NetBSD: Makefile,v 1.9.4.1 2010/06/03 10:18:20 spz Exp $
#

DISTNAME=	POE-Component-IRC-6.32
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Component-IRC/
COMMENT=	Fully event-driven IRC client module

DEPENDS+=	p5-POE>=0.3202:../../devel/p5-POE
DEPENDS+=	p5-POE-Component-Client-DNS>=0.99:../../net/p5-POE-Component-Client-DNS
DEPENDS+=	p5-POE-Component-Client-Ident-[0-9]*:../../net/p5-POE-Component-Client-Ident
DEPENDS+=	p5-POE-Filter-IRCD>=1.7:../../chat/p5-POE-Filter-IRCD
DEPENDS+=	p5-POE-Component-Pluggable>=1.24:../../devel/p5-POE-Component-Pluggable

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/POE/Component/IRC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
