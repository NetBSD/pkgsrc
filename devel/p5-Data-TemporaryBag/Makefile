# $NetBSD: Makefile,v 1.26 2023/07/06 09:38:57 wiz Exp $

DISTNAME=	Data-TemporaryBag-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-TemporaryBag
COMMENT=	Handle long size data using temporary file

PERL5_PACKLIST=		auto/Data/TemporaryBag/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
