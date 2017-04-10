# $NetBSD: Makefile,v 1.2 2017/04/10 09:35:01 joerg Exp $

DISTNAME=	Email-MIME-RFC2047-0.95
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/N/NW/NWELLNHOF/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/N/NW/NWELLNHOF/
COMMENT=	Encoding of non-ASCII MIME headers
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Email/MIME/RFC2047/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
