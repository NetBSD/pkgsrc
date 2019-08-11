# $NetBSD: Makefile,v 1.17 2019/08/11 13:18:29 wiz Exp $
#

DISTNAME=	DBIx-Schema-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
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
