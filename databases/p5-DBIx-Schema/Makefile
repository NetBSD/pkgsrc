# $NetBSD: Makefile,v 1.21 2023/07/06 09:38:25 wiz Exp $
#

DISTNAME=	DBIx-Schema-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBIx-Schema
COMMENT=	Simpler SQL Join interface

MAKE_PARAMS+=	--noprompt

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DBIx/Schema/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
