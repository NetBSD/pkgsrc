# $NetBSD: Makefile,v 1.38 2005/07/13 18:01:37 jlam Exp $

DISTNAME=	libnet-1.19
PKGNAME=	p5-Net-1.19
SVR4_PKGNAME=	p5net
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/libnet/Net/libnetFAQ.html
COMMENT=	Perl5 modules to access and use network protocols

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Net/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
