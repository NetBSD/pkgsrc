# $NetBSD: Makefile,v 1.36 2025/07/04 08:45:49 wiz Exp $

DISTNAME=	File-Which-1.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Which
COMMENT=	Portable implementation of the 'which' utility
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Which/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
