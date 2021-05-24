# $NetBSD: Makefile,v 1.22 2021/05/24 19:53:26 wiz Exp $

DISTNAME=	Net-Dev-MIBLoadOrder-1.1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Dev-MIBLoadOrder
COMMENT=	Perl5 module to determine MIB files load order

PERL5_PACKLIST=		auto/Net/Dev/Tools/MIB/MIBLoadOrder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
