# $NetBSD: Makefile,v 1.5 2018/08/22 09:44:26 wiz Exp $
#

DISTNAME=	Object-Accessor-0.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bingos/Object-Accessor/
COMMENT=	Module that allows per Object accessors (as opposed to per Class ..)
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Object/Accessor/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
