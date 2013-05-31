# $NetBSD: Makefile,v 1.12 2013/05/31 12:41:48 wiz Exp $

DISTNAME=	Net-CUPS-0.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
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
