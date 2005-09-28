# $NetBSD: Makefile,v 1.13 2005/09/28 20:52:24 rillig Exp $

DISTNAME=		mailagent-3.0.73
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:S/by-module/by-authors\/id\/RAM/g}

MAINTAINER=		itojun@itojun.org
COMMENT=		Sophisticated automatic mail-processing tool

USE_TOOLS+=		perl:run

NO_PACKAGE=		"Correct FQDN needs to be hardcoded"
INTERACTIVE_STAGE=	configure

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS=		-dres \
			-Dperlpath='${PERL5}' \
			-Dutmp='/var/run/utmp' \
			-Dprefix='${PREFIX}' -Dmansrc='${PREFIX}/man/man1' \
			-Dnotifypatches='false'
MAKE_ENV=		PATH=`${DIRNAME} ${PERL5}`:${PATH}
INSTALL_TARGET=		install install.man

pre-extract:
	@if [ `${SH} -c umask` != 0022 ]; then \
	  ${ECHO} "Please set umask to 022 before running make,"; \
	  ${ECHO} "or mailagent will not build successfully."; \
	  ${FALSE}; fi
	@if [ `${ID} -u` = 0 ]; then \
	  ${ECHO} "Do not build mailagent as root or it won't pass the sanity tests."; \
	  ${FALSE}; fi

pre-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/pre-configure

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mailagent
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mailagent/misc
	${CP} -pR ${WRKSRC}/misc/* ${PREFIX}/share/examples/mailagent/misc
	@${LN} -fs ${PREFIX}/lib/mailagent/examples \
		${PREFIX}/share/examples/mailagent/agent

.include "../../mk/bsd.pkg.mk"
