# $NetBSD: Makefile,v 1.17 2015/06/12 10:50:45 wiz Exp $

DISTNAME=	Net-Bind-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Bind
COMMENT=	Perl5 module to grovel DNS resolver information
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/Bind/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
