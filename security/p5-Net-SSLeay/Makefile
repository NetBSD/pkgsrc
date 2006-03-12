# $NetBSD: Makefile,v 1.37 2006/03/12 02:48:19 heinz Exp $

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

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
