# $NetBSD: Makefile,v 1.9 2020/09/08 13:09:58 wiz Exp $

DISTNAME=	Email-MIME-RFC2047-0.97
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	https://cpan.metacpan.org/authors/id/N/NW/NWELLNHOF/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Email::MIME::RFC2047
COMMENT=	Encoding of non-ASCII MIME headers
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Email/MIME/RFC2047/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
