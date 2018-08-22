# $NetBSD: Makefile,v 1.90 2018/08/22 09:46:27 wiz Exp $

DISTNAME=	Net-SSLeay-1.85
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-SSLeay/
COMMENT=	Perl5 module for using OpenSSL
LICENSE=	openssl

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Net/SSLeay/.packlist
MAKE_ENV+=		OPENSSL_PREFIX=${SSLBASE}
MAKE_ENV+=		PERL_MM_USE_DEFAULT=1	# avoid network question

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
