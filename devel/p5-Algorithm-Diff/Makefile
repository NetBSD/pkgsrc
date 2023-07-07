# $NetBSD: Makefile,v 1.35 2023/07/07 07:12:53 wiz Exp $

DISTNAME=	Algorithm-Diff-1.201
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Algorithm-Diff
COMMENT=	Perl module for diffing similar to diff(1)

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Algorithm/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
