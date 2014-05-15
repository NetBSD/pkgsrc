# $NetBSD: Makefile,v 1.62 2014/05/15 10:00:17 wiz Exp $

DISTNAME=	Net-SSLeay-1.61
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nsl
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-SSLeay/
COMMENT=	Perl5 module for using OpenSSL
LICENSE=	openssl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64

# see WRKSRC/inc/Module/Install/PRIVATE/Net/SSLeay.pm
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.3

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Net/SSLeay/.packlist
MAKE_ENV+=		OPENSSL_PREFIX=${SSLBASE}
MAKE_ENV+=		PERL_MM_USE_DEFAULT=1	# avoid network question
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
