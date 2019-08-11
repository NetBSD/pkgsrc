# $NetBSD: Makefile,v 1.7 2019/08/11 13:22:15 wiz Exp $

DISTNAME=		IO-SessionData-1.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/IO-SessionData
COMMENT=		Supporting module for SOAP::Lite
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/IO/SessionData/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
