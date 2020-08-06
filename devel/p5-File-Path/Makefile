# $NetBSD: Makefile,v 1.24 2020/08/06 00:24:55 gutteridge Exp $

DISTNAME=	File-Path-2.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Path
COMMENT=	Perl5 module to create or remove directory trees
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Path/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
