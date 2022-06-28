# $NetBSD: Makefile,v 1.12 2022/06/28 11:34:25 wiz Exp $

DISTNAME=	Email-MIME-RFC2047-0.97
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NW/NWELLNHOF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Email::MIME::RFC2047
COMMENT=	Encoding of non-ASCII MIME headers
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Email/MIME/RFC2047/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
