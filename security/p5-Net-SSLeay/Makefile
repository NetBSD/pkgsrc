# $NetBSD: Makefile,v 1.25 2003/11/12 03:39:43 jschauma Exp $

DISTNAME=	Net_SSLeay.pm-1.25
PKGNAME=	p5-${DISTNAME:S/Net_/Net-/:S/.pm//}
PKGREVISION=	1
SVR4_PKGNAME=	p5nsl
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://symlabs.com/Net_SSLeay/
COMMENT=	Perl5 module for using OpenSSL

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/SSLeay/.packlist
MAKE_PARAMS+=		${BUILDLINK_PREFIX.openssl}

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
