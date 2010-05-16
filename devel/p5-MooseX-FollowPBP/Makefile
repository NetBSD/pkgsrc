# $NetBSD: Makefile,v 1.1.1.1 2010/05/16 12:31:31 abs Exp $
#

DISTNAME=	MooseX-FollowPBP-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-FollowPBP/
COMMENT=	Name your accessors get_foo() and set_foo()
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0.93:../../devel/p5-Moose

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/FollowPBP/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
