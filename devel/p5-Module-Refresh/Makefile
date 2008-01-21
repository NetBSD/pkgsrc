# $NetBSD: Makefile,v 1.4 2008/01/21 13:55:29 abs Exp $
#

DISTNAME=	Module-Refresh-0.13
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mr
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Refresh/
COMMENT=	Perl5 module providing %INC files refreshing when updated on disk

PERL5_PACKLIST=		auto/Module/Refresh/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
