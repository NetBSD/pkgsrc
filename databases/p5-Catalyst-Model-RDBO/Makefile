# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:13:41 abs Exp $

DISTNAME=	Catalyst-Model-RDBO-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Model-RDBO/
COMMENT=	Rose::DB::Object model class for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.00:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Rose-DB-Object>=0:../../databases/p5-Rose-DB-Object

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Model/RDBO/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
