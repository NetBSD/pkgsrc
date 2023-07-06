# $NetBSD: Makefile,v 1.23 2023/07/06 09:40:45 wiz Exp $
#

DISTNAME=	MIME-EncWords-1.014.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MIME-EncWords
COMMENT=	Perl5 modules for decoding RFC 2047 encoded words (improved)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MIME-Charset>=1.007.1:../../mail/p5-MIME-Charset

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MIME/EncWords/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
