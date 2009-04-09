# $NetBSD: Makefile,v 1.18 2009/04/09 00:44:53 joerg Exp $

DISTNAME=		mailagent-3.0.73
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:S/by-module/by-authors\/id\/RAM/g}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Sophisticated automatic mail-processing tool

USE_TOOLS+=		perl:run

RESTRICTED=		Correct FQDN needs to be hardcoded
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
INTERACTIVE_STAGE=	configure

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-dres
CONFIGURE_ARGS+=	-Dperlpath=${PERL5:Q}
CONFIGURE_ARGS+=	-Dutmp='/var/run/utmp'
CONFIGURE_ARGS+=	-Dprefix=${PREFIX:Q}
CONFIGURE_ARGS+=	-Dmansrc=${PREFIX:Q}/man/man1
CONFIGURE_ARGS+=	-Dnotifypatches='false'
MAKE_ENV+=		PATH=`${DIRNAME} ${PERL5}`:${PATH:Q}
INSTALL_TARGET=		install install.man

MAILAGENT_DOMAIN?=		example.com
MAILAGENT_EMAIL?=		testuser@example.com
MAILAGENT_FQDN?=		test.example.com
MAILAGENT_ORGANIZATION?=	Example Company

BUILD_DEFS+=	MAILAGENT_DOMAIN MAILAGENT_EMAIL MAILAGENT_FQDN MAILAGENT_ORGANIZATION

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
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mailagent
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mailagent/misc
	${CP} -pR ${WRKSRC}/misc/* ${PREFIX}/share/examples/mailagent/misc
	${LN} -fs ${PREFIX}/lib/mailagent/examples \
		${PREFIX}/share/examples/mailagent/agent

.include "../../mk/bsd.pkg.mk"
