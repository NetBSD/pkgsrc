# $NetBSD: Makefile,v 1.6 2011/08/14 14:14:44 obache Exp $

DISTNAME=	Net-IPv6Addr-0.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

DEPENDS+=	p5-Math-Base85-[0-9]*:../../math/p5-Math-Base85
DEPENDS+=	p5-Net-IPv4Addr-[0-9]*:../../net/p5-Net-IPv4Addr

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Check the validity of IPv6 addresses

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/IPv6Addr/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
