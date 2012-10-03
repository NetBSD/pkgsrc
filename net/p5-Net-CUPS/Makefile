# $NetBSD: Makefile,v 1.5 2012/10/03 21:57:00 wiz Exp $

DISTNAME=	Net-CUPS-0.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	net print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-CUPS/
COMMENT=	Common Unix Printing System Interface
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Net/CUPS/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../print/cups/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
