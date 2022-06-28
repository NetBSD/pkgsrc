# $NetBSD: Makefile,v 1.21 2022/06/28 11:31:32 wiz Exp $

DISTNAME=		build-farm-4_15_1
PKGNAME=		${DISTNAME:S/build-farm/pgbuildfarm/:S/_/./g}
PKGREVISION=		6
CATEGORIES=		databases
MASTER_SITES=		http://www.pgbuildfarm.org/downloads/releases/
EXTRACT_SUFX=		.tgz

MAINTAINER=		nico@orgrim.net
HOMEPAGE=		http://www.pgbuildfarm.org/
COMMENT=		PostgreSQL Build Farm client
LICENSE=		postgresql-license

DEPENDS+=		git-base>=1.6:../../devel/git-base
DEPENDS+=		p5-libwww>=5.0:../../www/p5-libwww

WRKSRC=			${WRKDIR}/${DISTNAME:S/_/./g}
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
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	setnotes.pl update_personality.pl PGBuild/Options.pm
SUBST_SED.conf=		-e 's,build-farm.conf,${PKG_SYSCONFDIR}/build-farm.conf,'
SUBST_MESSAGE.conf=	Fixing default value for build-farm.conf

INSTALLATION_DIRS+=	${PMDIR}
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${PMDIR}/Modules

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/PGBuild/*.pm ${DESTDIR}${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/PGBuild/Modules/*.pm ${DESTDIR}${PMDIR}/Modules
	${INSTALL_DATA} ${WRKSRC}/build-farm.conf ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
