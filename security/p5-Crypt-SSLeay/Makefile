# $NetBSD: Makefile,v 1.42 2022/06/28 11:35:45 wiz Exp $

DISTNAME=	Crypt-SSLeay-0.72
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	security perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Crypt-SSLeay
COMMENT=	Crypt::SSLeay - OpenSSL glue that provides LWP https support
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Path-Class>=0.26:../../devel/p5-Path-Class
DEPENDS+=	p5-Try-Tiny>=0.19:../../devel/p5-Try-Tiny

PERL5_PACKLIST=		auto/Crypt/SSLeay/.packlist

MAKE_ENV+=		PERL_MM_USE_DEFAULT=1
MAKE_PARAMS+=		--lib=${SSLBASE}
MAKE_PARAMS+=		--libpath=${SSLBASE}/lib

post-extract:
	chmod a-x ${WRKSRC}/lib/Net/SSL.pm

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
