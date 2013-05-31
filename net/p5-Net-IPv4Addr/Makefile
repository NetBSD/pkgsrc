# $NetBSD: Makefile,v 1.10 2013/05/31 12:41:38 wiz Exp $

DISTNAME=	Net-IPv4Addr-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl extension for manipulating IPv4 addresses

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Net/IPv4Addr/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
