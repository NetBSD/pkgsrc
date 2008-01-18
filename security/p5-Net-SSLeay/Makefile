# $NetBSD: Makefile,v 1.43 2008/01/18 05:09:40 tnn Exp $

DISTNAME=	Net-SSLeay-1.32
PKGNAME=	p5-${DISTNAME:S/Net_/Net-/:S/.pm//}
PKGREVISION=	1
SVR4_PKGNAME=	p5nsl
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module for using OpenSSL

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

# see WRKSRC/inc/Module/Install/PRIVATE/Net/SSLeay.pm
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.3

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Net/SSLeay/.packlist
MAKE_ENV+=		OPENSSL_PREFIX=${SSLBASE}
MAKE_ENV+=		PERL_MM_USE_DEFAULT=1	# avoid network question
MAKE_PARAMS=		--skipdeps

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
