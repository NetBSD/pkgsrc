# $NetBSD: Makefile,v 1.101 2022/08/06 17:05:46 ast Exp $

DISTNAME=	Net-SSLeay-1.92
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-SSLeay
COMMENT=	Perl5 module for using OpenSSL
LICENSE=	openssl

TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
TEST_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

PERL5_PACKLIST=		auto/Net/SSLeay/.packlist
MAKE_ENV+=		OPENSSL_PREFIX=${SSLBASE}
MAKE_ENV+=		PERL_MM_USE_DEFAULT=1	# avoid network question
MAKE_ENV+=		DYLD_LIBRARY_PATH=${PREFIX}/lib # build on Mac OS X

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
