# $NetBSD: Makefile,v 1.31 2005/02/18 13:10:40 wiz Exp $

DISTNAME=	Net_SSLeay.pm-1.26
PKGNAME=	p5-${DISTNAME:S/Net_/Net-/:S/.pm//}
SVR4_PKGNAME=	p5nsl
CATEGORIES=	security perl5
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}
# inofficial version
MASTER_SITES=	http://www.fas.harvard.edu/~behrooz/

MAINTAINER=	shell@NetBSD.org
COMMENT=	Perl5 module for using OpenSSL

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/SSLeay/.packlist
MAKE_PARAMS+=		${SSLBASE}

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
