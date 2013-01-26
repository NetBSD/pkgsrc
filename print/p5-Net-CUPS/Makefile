# $NetBSD: Makefile,v 1.9 2013/01/26 21:38:43 adam Exp $

DISTNAME=	Net-CUPS-0.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	print net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-CUPS/
COMMENT=	Common Unix Printing System Interface
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Net/CUPS/.packlist

BUILDLINK_API_DEPENDS.cups+=	cups>=1.2.2
.include "../../print/cups/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
