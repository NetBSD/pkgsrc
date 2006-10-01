# $NetBSD: Makefile,v 1.38 2006/10/01 15:12:12 rillig Exp $

DISTNAME=	Net_SSLeay.pm-1.30
PKGNAME=	p5-${DISTNAME:S/Net_/Net-/:S/.pm//}
SVR4_PKGNAME=	p5nsl
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	shell@NetBSD.org
COMMENT=	Perl5 module for using OpenSSL

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Net/SSLeay/.packlist
MAKE_PARAMS=		${SSLBASE}

# Needs someone to press ^C when the test does not do any progress.
INTERACTIVE_STAGE=	test

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
