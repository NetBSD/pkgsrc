# $NetBSD: Makefile,v 1.5 2005/12/27 13:54:58 seb Exp $

DISTNAME=	Net-Dev-MIBLoadOrder-1.1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Dev-MIBLoadOrder/
COMMENT=	Perl5 module to determine MIB files load order

PERL5_PACKLIST=		auto/Net/Dev/Tools/MIB/MIBLoadOrder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
