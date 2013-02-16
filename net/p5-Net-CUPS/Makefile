# $NetBSD: Makefile,v 1.9 2013/02/16 11:23:59 wiz Exp $

DISTNAME=	Net-CUPS-0.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	net print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-CUPS/
COMMENT=	Common Unix Printing System Interface
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Net/CUPS/.packlist

.include "../../print/cups/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
