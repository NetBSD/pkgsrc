# $NetBSD: Makefile,v 1.24 2021/05/24 19:53:25 wiz Exp $

DISTNAME=	Net-Bind-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Bind
COMMENT=	Perl5 module to grovel DNS resolver information
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/Bind/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
