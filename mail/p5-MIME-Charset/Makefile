# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:34 joerg Exp $
#

DISTNAME=	MIME-Charset-1.006.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MIME-Charset/
COMMENT=	Perl5 module containing charset Informations for MIME

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MIME/Charset/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
