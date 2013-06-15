# $NetBSD: Makefile,v 1.25 2013/06/15 06:09:37 obache Exp $

DISTNAME=		mailagent-3.0.73
PKGREVISION=		4
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:S/by-module/by-authors\/id\/RAM/g}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Sophisticated automatic mail-processing tool
LICENSE=		artistic

DEPENDS+=		p5-Perl4-CoreLibs-[0-9]*:../../devel/p5-Perl4-CoreLibs

USE_TOOLS+=		perl:run

RESTRICTED=		Correct FQDN needs to be hardcoded
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

MAKE_JOBS_SAFE=		no

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-dres
CONFIGURE_ARGS+=	-Dperlpath=${PERL5:Q}
CONFIGURE_ARGS+=	-Dutmp='/var/run/utmp'
CONFIGURE_ARGS+=	-Dprefix=${PREFIX:Q}
CONFIGURE_ARGS+=	-Dmansrc=${PREFIX:Q}/${PKGMANDIR}/man1
CONFIGURE_ARGS+=	-Dnotifypatches='false'
CONFIGURE_ARGS+=	-Dcat=${CAT:Q}
INSTALL_TARGET=		install install.man

MAILAGENT_DOMAIN?=		example.com
MAILAGENT_EMAIL?=		testuser@example.com
MAILAGENT_FQDN?=		test.example.com
MAILAGENT_ORGANIZATION?=	Example Company

BUILD_DEFS+=	MAILAGENT_DOMAIN MAILAGENT_EMAIL MAILAGENT_FQDN MAILAGENT_ORGANIZATION

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	SCRIPTDIR=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	PRIVLIB=${DESTDIR}${PREFIX}/lib/mailagent
INSTALL_MAKE_FLAGS+=	MANSRC=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

CF=				${WRKSRC}/config.sh

pre-extract:
	if [ `${SH} -c umask` != 0022 ]; then \
	  ${ECHO} "Please set umask to 022 before running make,"; \
	  ${ECHO} "or mailagent will not build successfully."; \
	  ${FALSE}; fi
	if [ `${ID} -u` = 0 ]; then \
	  ${ECHO} "Do not build mailagent as root or it won't pass the sanity tests."; \
	  ${FALSE}; fi

pre-configure:
	${ECHO} "#!/bin/sh" > ${CF}
	${ECHO} "cf_email='${MAILAGENT_EMAIL}'" >> ${CF}
	${ECHO} "d_flockonly='define'" >> ${CF}
	if [ `${ECHO} ${MAILAGENT_DOMAIN} | tr A-Z a-z` = `${ECHO} ${MAILAGENT_FQDN} | tr A-Z a-z` ]; then \
		${ECHO} "d_hidnet='undef'" >> ${CF}; \
		${ECHO} "hiddennet=''" >> ${CF}; \
	else \
		${ECHO} "d_hidnet='define'" >> ${CF}; \
		${ECHO} "hiddennet='${MAILAGENT_DOMAIN}'" >> ${CF}; \
	fi
	${ECHO} "orgname='${MAILAGENT_ORGANIZATION}'" >> ${CF}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/mailagent
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/mailagent/misc
	${CP} -pR ${WRKSRC}/misc/* ${DESTDIR}${PREFIX}/share/examples/mailagent/misc

.include "../../mk/bsd.pkg.mk"
