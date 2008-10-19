# $NetBSD: Makefile,v 1.2 2008/10/19 19:17:51 he Exp $

DISTNAME=	Data-Pageset-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LL/LLAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~llap/Data-Pageset/
COMMENT=	Page numbering and page sets

DEPENDS+=   	p5-Data-Page>=2.00:../../devel/p5-Data-Page

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Data/Pageset/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
