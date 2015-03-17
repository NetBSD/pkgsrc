# $NetBSD: Makefile,v 1.15 2015/03/17 12:09:22 mef Exp $
#

DISTNAME=	Module-Refresh-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Refresh/
COMMENT=	Perl5 module providing %INC files refreshing when updated on disk
LICENSE=	${PERL5_LICENSE}

# Following line are really for 'make test', as an interim solution
BUILD_DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class

PERL5_PACKLIST=		auto/Module/Refresh/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
