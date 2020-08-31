# $NetBSD: Makefile,v 1.3 2020/08/31 18:07:30 wiz Exp $

DISTNAME=	B-Debug-1.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/R/RU/RURBAN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/B-Debug
COMMENT=	Walk Perl syntax tree, printing debug info about ops
LICENSE=	gnu-gpl-v1

USE_LANGUAGES=	# none
PERL5_PACKLIST=	auto/B/Debug/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
