# $NetBSD: Makefile,v 1.1 2010/03/09 19:41:21 pettai Exp $
#

DISTNAME=		List-Compare-0.37
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		perl5 textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=		pettai@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~jkeenan/List-Compare/
COMMENT=		Compare elements of two or more lists

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/List/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
