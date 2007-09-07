# $NetBSD: Makefile,v 1.44 2007/09/07 15:56:26 wiz Exp $

DISTNAME=	libnet-1.22
PKGNAME=	p5-Net-1.22
SVR4_PKGNAME=	p5net
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/libnet/
COMMENT=	Perl5 modules to access and use network protocols

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
