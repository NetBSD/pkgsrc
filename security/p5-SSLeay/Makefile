# $NetBSD: Makefile,v 1.3 2001/11/26 06:50:18 jlam Exp $
#

DISTNAME=		Crypt-SSLeay-0.22
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5csl
CATEGORIES=		security perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		damon@brodiefamily.org
COMMENT=		Crypt::SSLeay - OpenSSL glue that provides LWP https support

DEPENDS+=		p5-libwww>=5.48:../../www/p5-libwww

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/SSLeay/.packlist

do-configure:
	@cd ${WRKSRC} && ${SED} "s|@SSLBASE@|${BUILDLINK_DIR}|" Makefile.PL \
		> Makefile.PL.tmp && ${MV} Makefile.PL.tmp Makefile.PL
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
