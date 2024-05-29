# $NetBSD: Makefile,v 1.5 2024/05/29 03:01:56 riastradh Exp $

.include "../../devel/git/Makefile.common"

PKGNAME=	git-perlscripts-${GIT_VERSION}
PKGREVISION=	2
COMMENT=	Git commands that rely on Perl

CONFLICTS+=	git-base<2.41.0nb1

DEPENDS+=	p5-DBD-SQLite>=0:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI
DEPENDS+=	p5-Error>=0.17015:../../devel/p5-Error
DEPENDS+=	p5-Email-Valid>=0.190:../../mail/p5-Email-Valid
DEPENDS+=	p5-MailTools>=2.11:../../mail/p5-MailTools
DEPENDS+=	p5-Net-SMTP-SSL>=1.01:../../mail/p5-Net-SMTP-SSL
DEPENDS+=	p5-Authen-SASL>=1.0:../../security/p5-Authen-SASL

USE_TOOLS+=	pax perl:run

REPLACE_PERL+=		*.perl */*.perl */*/*.perl
REPLACE_PERL+=		contrib/hooks/update-paranoid

CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}

BUILD_TARGET=		build-perl-script build-perl-libs
BUILD_TARGET+=		git-instaweb git-request-pull # sh scripts call perl
INSTALL_TARGET=		install-perl-script

MAKE_FLAGS+=		INSTALL=${INSTALL:Q}
MAKE_ENV+=		PERLLIBDIR=${PERL5_INSTALLVENDORLIB}

INSTALLATION_DIRS+=	libexec/git-core
INSTALLATION_DIRS+=	${PERL5_INSTALLVENDORLIB}

post-install:
	${INSTALL} ${WRKSRC}/git-instaweb ${DESTDIR}${PREFIX}/libexec/git-core
	${INSTALL} ${WRKSRC}/git-request-pull ${DESTDIR}${PREFIX}/libexec/git-core
	cd ${WRKSRC}/perl/build/lib && \
	${PAX} -rw -pp . ${DESTDIR}${PERL5_INSTALLVENDORLIB}

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/vars.mk"
.include "../../mk/bsd.pkg.mk"
