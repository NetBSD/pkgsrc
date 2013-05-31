# $NetBSD: Makefile,v 1.13 2013/05/31 12:41:37 wiz Exp $

DISTNAME=	Net-Dev-MIBLoadOrder-1.1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Dev-MIBLoadOrder/
COMMENT=	Perl5 module to determine MIB files load order

PERL5_PACKLIST=		auto/Net/Dev/Tools/MIB/MIBLoadOrder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
