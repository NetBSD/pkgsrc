# $NetBSD: Makefile,v 1.1.1.1 2006/04/18 18:55:18 cube Exp $

DISTNAME=	MIME-Lite-HTML-1.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	cube@NetBSD.org
COMMENT=	Perl5 module to transform a HTML page into a MIME-Lite mail

DEPENDS+=	p5-MIME-Lite>=3.01:../../mail/p5-MIME-Lite
DEPENDS+=	p5-libwww>=5.805:../../www/p5-libwww

PERL5_PACKLIST=	auto/MIME/Lite/HTML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
