# $NetBSD: Makefile,v 1.14 2004/10/03 00:18:12 tv Exp $
#

DISTNAME=	Crypt-SSLeay-0.51
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5csl
CATEGORIES=	security perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	shell@NetBSD.org
COMMENT=	Crypt::SSLeay - OpenSSL glue that provides LWP https support

DEPENDS+=	p5-libwww>=5.48:../../www/p5-libwww

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/SSLeay/.packlist

SUBST_CLASSES+=		openssl
SUBST_STAGE.openssl=	pre-configure
SUBST_MESSAGE.openssl=	"Fixing path to OpenSSL."
SUBST_FILES.openssl=	Makefile.PL
SUBST_SED.openssl=	-e 's|%%SSLBASE%%|${BUILDLINK_PREFIX.openssl}|g'

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
