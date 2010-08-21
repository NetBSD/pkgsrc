# $NetBSD: Makefile,v 1.3 2010/08/21 16:33:12 seb Exp $
#

DISTNAME=	Array-RefElem-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Array::RefElem
COMMENT=	Set up array elements as aliases

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Array/RefElem/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
