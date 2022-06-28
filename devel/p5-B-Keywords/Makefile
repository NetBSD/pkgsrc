# $NetBSD: Makefile,v 1.32 2022/06/28 11:31:55 wiz Exp $

DISTNAME=	B-Keywords-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/B-Keywords
COMMENT=	Perl 5 module providing lists of reserved barewords and symbol names
LICENSE=	gnu-gpl-v2 OR artistic

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/B/Keywords/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
