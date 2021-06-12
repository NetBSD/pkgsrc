# $NetBSD: Makefile,v 1.32 2021/06/12 13:51:18 wen Exp $

DISTNAME=	File-Which-1.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Which
COMMENT=	Portable implementation of the 'which' utility
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Which/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
