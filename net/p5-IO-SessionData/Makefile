# $NetBSD: Makefile,v 1.3 2016/06/08 19:24:08 wiz Exp $

DISTNAME=		IO-SessionData-1.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-SessionData/
COMMENT=		Supporting module for SOAP::Lite
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/IO/SessionData/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
