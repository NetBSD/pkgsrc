# $NetBSD: Makefile,v 1.26 2009/02/25 21:06:00 sno Exp $
#

DISTNAME=	SQL-Statement-1.19
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sqs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SQL-Statement/
COMMENT=	Small, abstract SQL engine

DEPENDS+=	p5-Clone>=0.30:../../devel/p5-Clone
DEPENDS+=	p5-Params-Util>=0.35:../../devel/p5-Params-Util
DEPENDS+=	p5-Test-Simple>=0.86:../../devel/p5-Test-Simple

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Test-Simple>=0.86:../../devel/p5-Test-Simple
DEPENDS+=	p5-Params-Util>=0.35:../../devel/p5-Params-Util
DEPENDS+=	p5-Clone>=0.30:../../devel/p5-Clone

PERL5_PACKLIST=		auto/SQL/Statement/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
