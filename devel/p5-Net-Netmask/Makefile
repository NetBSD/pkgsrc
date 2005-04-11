# $NetBSD: Makefile,v 1.6 2005/04/11 21:45:33 tv Exp $

DISTNAME=	Net-Netmask-1.9011
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	charlie@rubberduck.com
COMMENT=	Perl5 module to parse and manipulate IP network blocks

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/Netmask/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
