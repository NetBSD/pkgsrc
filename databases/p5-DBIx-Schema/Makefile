# $NetBSD: Makefile,v 1.2 2006/03/04 21:29:10 jlam Exp $
#

DISTNAME=	DBIx-Schema-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Schema/
COMMENT=	Simpler SQL Join interface

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_PARAMS+=	--noprompt

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DBIx/Schema/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
