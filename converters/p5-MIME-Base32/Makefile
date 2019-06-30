# $NetBSD: Makefile,v 1.17 2019/06/30 20:14:17 nia Exp $

DISTNAME=	MIME-Base32-1.303
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MIME-Base32
COMMENT=	Perl5 module for Base32 encoding
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/MIME/Base32/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
