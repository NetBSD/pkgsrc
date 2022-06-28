# $NetBSD: Makefile,v 1.135 2022/06/28 11:35:48 wiz Exp $

DISTNAME=	IO-Socket-SSL-2.072
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Socket-SSL
COMMENT=	Perl5 SSL socket interface class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Socket-INET6-[0-9]*:../../net/p5-IO-Socket-INET6
DEPENDS+=	p5-Net-LibIDN-[0-9]*:../../net/p5-Net-LibIDN
DEPENDS+=	p5-Net-SSLeay>=1.86:../../security/p5-Net-SSLeay
DEPENDS+=	p5-Mozilla-CA-[0-9]*:../../security/p5-Mozilla-CA

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IO/Socket/SSL/.packlist

SUBST_CLASSES.MirBSD+=	openssl
SUBST_STAGE.openssl=	pre-configure
SUBST_MESSAGE.openssl=	Adapting minimum OpenSSL version.
SUBST_FILES.openssl=	Makefile.PL
SUBST_SED.openssl=	-e 's/openssl < 0x00908000/openssl < 0x00907000/'

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
