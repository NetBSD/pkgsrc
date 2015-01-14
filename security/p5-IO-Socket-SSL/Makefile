# $NetBSD: Makefile,v 1.82 2015/01/14 13:23:10 wiz Exp $

DISTNAME=	IO-Socket-SSL-2.009
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SU/SULLR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Socket-SSL/
COMMENT=	Perl5 SSL socket interface class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Socket-INET6-[0-9]*:../../net/p5-IO-Socket-INET6
DEPENDS+=	p5-Net-LibIDN-[0-9]*:../../net/p5-Net-LibIDN
DEPENDS+=	p5-Net-SSLeay>=1.59:../../security/p5-Net-SSLeay

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IO/Socket/SSL/.packlist

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "MirBSD"
SUBST_CLASSES+=			openssl
SUBST_STAGE.openssl=		pre-configure
SUBST_MESSAGE.openssl=		Adapting minimum OpenSSL version.
SUBST_FILES.openssl=		Makefile.PL
SUBST_SED.openssl=		-e 's/openssl < 0x00908000/openssl < 0x00907000/'
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
