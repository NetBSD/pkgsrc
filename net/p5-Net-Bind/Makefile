# $NetBSD: Makefile,v 1.25 2022/06/28 11:35:08 wiz Exp $

DISTNAME=	Net-Bind-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Bind
COMMENT=	Perl5 module to grovel DNS resolver information
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/Bind/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
