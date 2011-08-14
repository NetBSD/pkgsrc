# $NetBSD: Makefile,v 1.7 2011/08/14 13:25:25 obache Exp $
#

DISTNAME=	MIME-EncWords-1.012
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MIME-EncWords/
COMMENT=	Perl5 modules for decoding RFC 2047 encoded words (improved)
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-MIME-Charset>=1.007.1:../../mail/p5-MIME-Charset

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MIME/EncWords/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
