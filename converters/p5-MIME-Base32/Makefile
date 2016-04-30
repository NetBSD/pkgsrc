# $NetBSD: Makefile,v 1.12 2016/04/30 13:51:45 schmonz Exp $

DISTNAME=	MIME-Base32-1.301
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MIME-Base32/
COMMENT=	Perl5 module for Base32 encoding
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/MIME/Base32/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
