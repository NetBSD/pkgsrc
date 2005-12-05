# $NetBSD: Makefile,v 1.2 2005/12/05 20:50:48 rillig Exp $

DISTNAME=	Net-IPv4Addr-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	adrianp@NetBSD.org
COMMENT=	Perl extension for manipulating IPv4 addresses

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Net/IPv4Addr/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
