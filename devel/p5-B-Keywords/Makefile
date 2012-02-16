# $NetBSD: Makefile,v 1.9 2012/02/16 06:26:23 sno Exp $

DISTNAME=	B-Keywords-1.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/B-Keywords/
COMMENT=	Perl 5 module providing lists of reserved barewords and symbol names
LICENSE=	gnu-gpl-v2 OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/B/Keywords/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
