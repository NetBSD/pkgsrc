# $NetBSD: Makefile,v 1.16 2006/03/04 21:30:22 jlam Exp $
#

DISTNAME=	Net-Server-0.88
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nts
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seamons.com/net_server.html
COMMENT=	Perl5 modules for network services engine

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Net/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
