# $NetBSD: Makefile,v 1.6 2003/02/09 08:09:08 shell Exp $
#

DISTNAME=	Crypt-SSLeay-0.47
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5csl
CATEGORIES=	security perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	shell@netbsd.org
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
