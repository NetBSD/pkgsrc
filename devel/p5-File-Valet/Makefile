# $NetBSD: Makefile,v 1.1 2020/09/22 01:50:23 mrg Exp $

DISTNAME=	File-Valet-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Valet
COMMENT=	Perl5 file utilities
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Valet/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
