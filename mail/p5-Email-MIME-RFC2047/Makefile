# $NetBSD: Makefile,v 1.13 2023/07/06 09:40:44 wiz Exp $

DISTNAME=	Email-MIME-RFC2047-0.97
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NW/NWELLNHOF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Email::MIME::RFC2047
COMMENT=	Encoding of non-ASCII MIME headers
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Email/MIME/RFC2047/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
