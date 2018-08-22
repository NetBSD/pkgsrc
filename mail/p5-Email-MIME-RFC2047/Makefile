# $NetBSD: Makefile,v 1.5 2018/08/22 09:45:28 wiz Exp $

DISTNAME=	Email-MIME-RFC2047-0.97
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/N/NW/NWELLNHOF/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/N/NW/NWELLNHOF/
COMMENT=	Encoding of non-ASCII MIME headers
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Email/MIME/RFC2047/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
