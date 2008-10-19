# $NetBSD: Makefile,v 1.3 2008/10/19 19:18:20 he Exp $
#

DISTNAME=	MIME-EncWords-1.010.101
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MIME-EncWords/
COMMENT=	Perl5 modules for decoding RFC 2047 encoded words (improved)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-MIME-Charset>=1.006.2:../../mail/p5-MIME-Charset

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MIME/EncWords/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
