# $NetBSD: Makefile,v 1.3 2001/11/26 06:50:10 jlam Exp $

DISTNAME=		Net-IRC-0.70
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5nir
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		damon@brodiefamily.org
HOMEPAGE=		http://theoryx5.uwinnipeg.ca/CPAN/data/Net-IRC/Connection.html
COMMENT=		Net::IRC - Perl Internet Relay Chat (IRC) Module

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/IRC/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
