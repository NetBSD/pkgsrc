# $NetBSD: Makefile,v 1.13 2017/06/05 14:24:42 ryoon Exp $
#

DISTNAME=		List-Compare-0.53
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		perl5 textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=		pettai@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~jkeenan/List-Compare/
COMMENT=		Compare elements of two or more lists
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/List/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
