# $NetBSD: Makefile,v 1.26 2004/01/05 22:16:25 jlam Exp $

DISTNAME=	Net_SSLeay.pm-1.25
PKGNAME=	p5-${DISTNAME:S/Net_/Net-/:S/.pm//}
PKGREVISION=	1
SVR4_PKGNAME=	p5nsl
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://symlabs.com/Net_SSLeay/
COMMENT=	Perl5 module for using OpenSSL

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/SSLeay/.packlist
MAKE_PARAMS+=		${SSLBASE}

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
