# $NetBSD: Makefile,v 1.1.1.1 2000/12/15 00:36:30 wiz Exp $

DISTNAME=	sirc-2.211
CATEGORIES=	chat
MASTER_SITES=	http://www.iagora.com/~espel/sirc/ \
		http://www.iagora.com/~espel/sirc/scripts/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}	\
		${SIRC_SCRIPTS}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.iagora.com/~espel/sirc/sirc.html

USE_PERL5=	# defined

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
SIRC_SCRIPTS= \
		adcc.pl				\
		akickban.pl			\
		avoice.pl			\
		country.pl			\
		finger.pl			\
		ftp.pl				\
		howl.pl				\
		hotmail.pl			\
		lastlog.pl			\
		nocolor.pl			\
		patattack.pl			\
		prefix.pl			\
		quiet.pl			\
		quit.pl				\
		ssfe.diff			\
		thx.pl				\
		winnuke.pl			\
		www.pl				\
		yiff.pl

NO_CONFIGURE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	sirc

.include "../../mk/bsd.prefs.mk"
.if defined(DEFAULT_IRC_SERVER)
IRC_SERVER=	${DEFAULT_IRC_SERVER}
.else
IRC_SERVER=	us.undernet.org
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/sirc
	cd ${WRKSRC} ; ( \
		${ECHO} "y" ; \
		${ECHO} "" ; \
		${ECHO} "" ; \
		${ECHO} "" ; \
		${ECHO} "-O3" ; \
		${ECHO} "" ; \
		${ECHO} "${PERL5}" ; \
		${ECHO} "${PREFIX}/bin" ; \
		${ECHO} "y" ; \
		${ECHO} "${PREFIX}/lib/sirc" ; \
		${ECHO} "y" ; \
		${ECHO} "n" ; \
		${ECHO} "${PREFIX}/man/man1" ; \
		${ECHO} "${IRC_SERVER}" ; \
		${ECHO} "" ; \
	) | ./install
	${INSTALL_DATA_DIR} ${PREFIX}/lib/sirc/scripts
	@for i in ${SIRC_SCRIPTS} ; do \
		${ECHO} installing $$i ; \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$i ${PREFIX}/lib/sirc/scripts/$$i ; done

.include "../../mk/bsd.pkg.mk"
