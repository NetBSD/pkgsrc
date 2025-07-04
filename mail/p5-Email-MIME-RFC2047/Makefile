# $NetBSD: Makefile,v 1.15 2025/07/04 08:47:19 wiz Exp $

DISTNAME=	Email-MIME-RFC2047-0.97
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NW/NWELLNHOF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Email::MIME::RFC2047
COMMENT=	Encoding of non-ASCII MIME headers
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Email/MIME/RFC2047/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
