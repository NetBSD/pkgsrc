# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:14 joerg Exp $

DISTNAME=	Clone-PP-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Clone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Clone-PP/
COMMENT=	Recursively copy Perl datatypes

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Clone/PP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
