# $NetBSD: Makefile,v 1.14 2012/01/26 19:38:09 rhaen Exp $

DISTNAME=	Net-Netmask-1.9016
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	charlie@rubberduck.com
COMMENT=	Perl5 module to parse and manipulate IP network blocks

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Net/Netmask/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
