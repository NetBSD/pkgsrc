# $NetBSD: Makefile,v 1.25 2013/05/31 12:41:40 wiz Exp $

DISTNAME=	Net-TFTP-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5ntf
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~gbarr/Net-TFTP-0.17/
COMMENT=	Perl5 module for TFTP transfers
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/TFTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
