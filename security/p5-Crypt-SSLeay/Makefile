# $NetBSD: Makefile,v 1.7 2007/06/09 13:18:57 wiz Exp $
#

DISTNAME=	Crypt-SSLeay-0.55
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5csl
CATEGORIES=	security perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Crypt-SSLeay/
COMMENT=	Crypt::SSLeay - OpenSSL glue that provides LWP https support

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Crypt/SSLeay/.packlist

MAKE_ENV+=		PERL_MM_USE_DEFAULT=1
MAKE_PARAMS+=		--lib=${SSLBASE}

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
