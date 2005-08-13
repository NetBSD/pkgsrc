# $NetBSD: Makefile,v 1.1.1.1 2005/08/13 07:56:40 adrianp Exp $

DISTNAME=	Net-IPv4Addr-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	adrianp@NetBSD.org
COMMENT=	Perl extension for manipulating IPv4 addresses.

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Net/IPv4Addr/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
