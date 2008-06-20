# $NetBSD: Makefile,v 1.3 2008/06/20 01:09:15 joerg Exp $
#

DISTNAME=	Date-Simple-3.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	geeogeegeeoh@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~yves/Date-Simple/
COMMENT=	A simple date object

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Date/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
