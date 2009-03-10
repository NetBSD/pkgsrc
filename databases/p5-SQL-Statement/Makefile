# $NetBSD: Makefile,v 1.27 2009/03/10 17:38:24 sno Exp $
#

DISTNAME=	SQL-Statement-1.20
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sqs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SQL-Statement/
COMMENT=	Small, abstract SQL engine

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Test-Simple>=0.86:../../devel/p5-Test-Simple
DEPENDS+=	p5-Params-Util>=0.35:../../devel/p5-Params-Util
DEPENDS+=	p5-Clone>=0.30:../../devel/p5-Clone

PERL5_PACKLIST=		auto/SQL/Statement/.packlist

pre-configure:
	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
