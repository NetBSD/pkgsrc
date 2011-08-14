# $NetBSD: Makefile,v 1.35 2011/08/14 08:18:11 obache Exp $
#

DISTNAME=	SQL-Statement-1.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5sqs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SQL-Statement/
COMMENT=	Small, abstract SQL engine
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.86}:../../devel/p5-Test-Simple

DEPENDS+=	p5-Clone>=0.30:../../devel/p5-Clone
DEPENDS+=	p5-Params-Util>=1.00:../../devel/p5-Params-Util

CONFLICTS+=	p5-DBI<=1.611

PERL5_PACKLIST=		auto/SQL/Statement/.packlist
MAKE_ENV+=		SQL_STATEMENT_WARN_UPDATE=sure

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../databases/p5-DBI/buildlink3.mk"
BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.612
BUILDLINK_DEPMETHOD.p5-DBI=	build

.include "../../mk/bsd.pkg.mk"
