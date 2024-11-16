# $NetBSD: Makefile,v 1.22 2024/11/16 12:04:49 wiz Exp $
#

DISTNAME=	Object-Declare-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Object-Declare
COMMENT=	Perl 5 module providing declarative object constructor
LICENSE=	mit

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Object/Declare/.packlist

DEPENDS+=	p5-Sub-Override-[0-9]*:../../devel/p5-Sub-Override

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
