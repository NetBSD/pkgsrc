# $NetBSD: Makefile,v 1.4 2002/01/19 03:19:12 mjl Exp $
#

DISTNAME=		Crypt-SSLeay-0.35
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5csl
CATEGORIES=		security perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		shell@shellhung.org
COMMENT=		Crypt::SSLeay - OpenSSL glue that provides LWP https support

DEPENDS+=		p5-libwww>=5.48:../../www/p5-libwww

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/SSLeay/.packlist

post-patch:
	@cd ${WRKSRC} && ${SED} "s|%%SSLBASE%%|${BUILDLINK_DIR}|" Makefile.PL \
		> Makefile.PL.tmp && ${MV} Makefile.PL.tmp Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
