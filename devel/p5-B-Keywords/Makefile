# $NetBSD: Makefile,v 1.19 2017/06/05 14:22:37 ryoon Exp $

DISTNAME=	B-Keywords-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/B-Keywords/
COMMENT=	Perl 5 module providing lists of reserved barewords and symbol names
LICENSE=	gnu-gpl-v2 OR artistic

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/B/Keywords/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
