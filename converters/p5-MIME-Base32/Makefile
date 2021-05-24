# $NetBSD: Makefile,v 1.20 2021/05/24 19:49:22 wiz Exp $

DISTNAME=	MIME-Base32-1.303
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MIME-Base32
COMMENT=	Perl5 module for Base32 encoding
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/MIME/Base32/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
