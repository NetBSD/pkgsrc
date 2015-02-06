# $NetBSD: Makefile,v 1.1 2015/02/06 05:11:38 mef Exp $
#

DISTNAME=	MooseX-Role-Tempdir-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~iamb/MooseX-Role-Tempdir/
COMMENT=	(Perl Module)  Moose role to provide temporary directories
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/MooseX/Role/Tempdir/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
