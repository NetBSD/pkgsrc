# $NetBSD: Makefile,v 1.7 2012/10/03 00:20:14 asau Exp $

DISTNAME=	MIME-Base32-1.02a
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MIME-Base32/
COMMENT=	Perl5 module for Base32 encoding
LICENSE=	${PERL5_LICENSE}

# needed for 1.02a
WRKSRC=			${WRKDIR}/${DISTNAME:S/a$//}

PERL5_PACKLIST=		auto/MIME/Base32/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
