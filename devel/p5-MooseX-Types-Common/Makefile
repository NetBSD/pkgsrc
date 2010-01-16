# $NetBSD: Makefile,v 1.3 2010/01/16 17:56:53 sno Exp $
#

DISTNAME=	MooseX-Types-Common-0.001001
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Types-Common/
COMMENT=	Commonly-used type constraints that do not ship with Moose by default
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0.39:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.04:../../devel/p5-MooseX-Types

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Types/Common/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
