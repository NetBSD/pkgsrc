# $NetBSD: Makefile,v 1.9 2003/11/12 03:39:43 jschauma Exp $
#

DISTNAME=	Crypt-SSLeay-0.51
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5csl
CATEGORIES=	security perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	shell@NetBSD.org
COMMENT=	Crypt::SSLeay - OpenSSL glue that provides LWP https support

DEPENDS+=	p5-libwww>=5.48:../../www/p5-libwww

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/SSLeay/.packlist

post-patch:
	@cd ${WRKSRC} && ${SED} "s|%%SSLBASE%%|${BUILDLINK_DIR}|" Makefile.PL \
		> Makefile.PL.tmp && ${MV} Makefile.PL.tmp Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
