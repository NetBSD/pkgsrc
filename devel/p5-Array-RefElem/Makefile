# $NetBSD: Makefile,v 1.2 2008/10/19 19:17:47 he Exp $
#

DISTNAME=	Array-RefElem-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
