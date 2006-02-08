# $NetBSD: Makefile,v 1.1.1.1 2006/02/08 08:22:51 seb Exp $
#

DISTNAME=	Module-Refresh-0.09
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mr
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Refresh/
COMMENT=	Perl5 module providing %INC files refreshing when updated on disk

PERL5_PACKLIST=		auto/Module/Refresh/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
