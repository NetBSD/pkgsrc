# $NetBSD: Makefile,v 1.19 2023/07/06 09:39:53 wiz Exp $

DISTNAME=	PerlIO-gzip-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PerlIO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl extension to provide a PerlIO layer to gzip/gunzip
HOMEPAGE=	https://metacpan.org/release/PerlIO-gzip
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES+=	c

PERL5_PACKLIST=		auto/PerlIO/gzip/.packlist

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
