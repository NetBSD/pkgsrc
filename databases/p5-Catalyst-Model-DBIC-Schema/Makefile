# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:13:24 abs Exp $

DISTNAME=	Catalyst-Model-DBIC-Schema-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Model-DBIC-Schema/
COMMENT=	DBIx::Class::Schema Model Class

DEPENDS+=	p5-Catalyst-Runtime>=5.64:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Accessor>=0.22:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Accessor>=0.02:../../devel/p5-Class-Data-Accessor
DEPENDS+=	p5-DBIx-Class>=0.07:../../databases/p5-DBIx-Class
DEPENDS+=	p5-UNIVERSAL-require>=0.10:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-Catalyst-Devel>=1:../../www/p5-Catalyst-Devel
DEPENDS+=	p5-DBIx-Class-Schema-Loader>=0.03012:../../databases/p5-DBIx-Class-Schema-Loader

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Model/DBIC/Schema/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
