# $NetBSD: Makefile,v 1.7 2019/08/11 13:20:03 wiz Exp $
#

DISTNAME=	Object-Accessor-0.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Object-Accessor
COMMENT=	Module that allows per Object accessors (as opposed to per Class ..)
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Object/Accessor/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
