# $NetBSD: Makefile,v 1.4 2013/05/31 12:41:38 wiz Exp $

DISTNAME=	Net-Frame-Layer-IPv6-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Internet Protocol v6 layer object
HOMEPAGE=	http://search.cpan.org/dist/Net-Frame-Layer-IPv6/
LICENSE=	artistic

DEPENDS+=	p5-Net-Frame-[0-9]*:../../net/p5-Net-Frame
DEPENDS+=	p5-Bit-Vector-[0-9]*:../../devel/p5-Bit-Vector

PKG_INSTALLATION_TYPES=		overwrite pkgviews

PERL5_PACKLIST=		auto/Net/Frame/Layer/IPv6/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
