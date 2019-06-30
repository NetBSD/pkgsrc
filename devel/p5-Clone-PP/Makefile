# $NetBSD: Makefile,v 1.16 2019/06/30 20:14:44 nia Exp $

DISTNAME=	Clone-PP-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Clone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Clone-PP
COMMENT=	Recursively copy Perl datatypes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Clone/PP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
