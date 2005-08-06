# $NetBSD: Makefile,v 1.8 2005/08/06 06:19:12 jlam Exp $

DISTNAME=	Net-Netmask-1.9011
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	charlie@rubberduck.com
COMMENT=	Perl5 module to parse and manipulate IP network blocks

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Net/Netmask/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
