# $NetBSD: Makefile,v 1.68 2018/08/22 09:45:57 wiz Exp $

DISTNAME=	libnet-3.11
PKGNAME=	p5-${DISTNAME:S/libnet/Net/}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/libnet/
COMMENT=	Perl5 modules to access and use network protocols
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
