# $NetBSD: Makefile,v 1.2 2022/01/22 15:05:01 bsiegert Exp $

GITHUB_PROJECT=	pgFormatter
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	pgFormatter-5.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases textproc perl5
MASTER_SITES=	${MASTER_SITE_GITHUB:=darold/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/darold/pgFormatter/
COMMENT=	PostgreSQL SQL syntax beautifier
LICENSE=	postgresql-license

PERL5_PACKLIST=	auto/pgFormatter/.packlist
USE_LANGUAGES=	# none

DOCDIR=		${PREFIX}/share/doc/pgFormatter

INSTALLATION_DIRS+=		${DOCDIR}

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		doc/pg_format.pod
SUBST_SED.fix-paths=		-e 's,doc/pg_format.conf.sample,${DOCDIR}/pg_format.conf.sample,g'

REPLACE_PERL=	pg_format

post-install:
.for doc in ChangeLog LICENSE README doc/pg_format.conf.sample
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${DOCDIR}
.endfor


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
