# $NetBSD: Makefile,v 1.16 2002/08/20 14:39:14 wiz Exp $

DISTNAME=	Net_SSLeay.pm-1.19
PKGNAME=	p5-${DISTNAME:S/Net_/Net-/:S/.pm//}
SVR4_PKGNAME=	p5nsl
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	shell@netbsd.org
HOMEPAGE=	http://symlabs.com/Net_SSLeay/
COMMENT=	perl5 module for using OpenSSL

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/SSLeay/.packlist
MAKE_PARAMS=		${BUILDLINK_DIR}

USE_OPENSSL_VERSION=	${OPENSSL_VERSION_096G}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../lang/perl5/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
