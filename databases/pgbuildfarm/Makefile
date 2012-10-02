# $NetBSD: Makefile,v 1.3 2012/10/02 21:25:38 asau Exp $
#

DISTNAME=		build-farm-4_5
PKGNAME=		${DISTNAME:S/build-farm/pgbuildfarm/:S/_/./}
CATEGORIES=		databases
MASTER_SITES=		http://pgfoundry.org/frs/download.php/3028/
EXTRACT_SUFX=		.tgz

MAINTAINER=		nico@orgrim.net
HOMEPAGE=		http://www.pgbuildfarm.org/
COMMENT=		PostgreSQL Build Farm client
LICENSE=		postgresql-license

DEPENDS+=		scmgit-base>=1.6:../../devel/scmgit-base
DEPENDS+=		p5-libwww>=5.0:../../www/p5-libwww
DEPENDS+=		p5-Digest-SHA1>=2.13:../../security/p5-Digest-SHA1

WRKSRC=			${WRKDIR}/${DISTNAME:S/_/./}
NO_BUILD=		yes
USE_LANGUAGES=		# none
USE_TOOLS+=		perl:run
AUTO_MKDIRS=		yes
REPLACE_PERL+=		${WRKSRC}/*.pl

EGDIR=			${PREFIX}/share/examples/pgbuildfarm
PMDIR=			${PREFIX}/${PERL5_SUB_INSTALLVENDORLIB}/PGBuild
CONF_FILES=		${EGDIR}/build-farm.conf \
			${PKG_SYSCONFDIR}/build-farm.conf
PKG_SYSCONFSUBDIR=	pgbuildfarm

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	setnotes.pl update_personality.pl PGBuild/Options.pm
SUBST_SED.conf=		-e 's,build-farm.conf,${PKG_SYSCONFDIR}/build-farm.conf,'
SUBST_MESSAGE.conf=	Fixing default value for build-farm.conf

INSTALLATION_DIRS+= ${PMDIR}
INSTALLATION_DIRS+= ${EGDIR}

.include "../../lang/perl5/dirs.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/PGBuild/*.pm ${DESTDIR}${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/build-farm.conf ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
