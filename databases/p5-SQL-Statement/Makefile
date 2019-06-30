# $NetBSD: Makefile,v 1.52 2019/06/30 20:14:28 nia Exp $

DISTNAME=	SQL-Statement-1.412
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SQL-Statement
COMMENT=	Small, abstract SQL engine
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Clone>=0.30:../../devel/p5-Clone
DEPENDS+=	p5-Params-Util>=1.00:../../devel/p5-Params-Util
DEPENDS+=	p5-Math-Base-Convert>=0:../../math/p5-Math-Base-Convert
DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime

BUILD_DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep

CONFLICTS+=	p5-DBI<=1.622

PERL5_PACKLIST=		auto/SQL/Statement/.packlist
MAKE_ENV+=		SQL_STATEMENT_WARN_UPDATE=sure

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
