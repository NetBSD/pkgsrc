# $NetBSD: Makefile,v 1.10 1998/11/01 13:51:09 hubertf Exp $

DISTNAME=	sirc-2.211
CATEGORIES=	net
MASTER_SITES=	http://www.eleves.ens.fr:8080/home/espel/sirc/ \
		http://www.eleves.ens.fr:8080/home/espel/sirc/scripts/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}	\
		${SIRC_SCRIPTS}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.eleves.ens.fr:8080/home/espel/sirc/

USE_PERL5=	YES

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
		quit.pl				\
		ssfe.diff			\
		www.pl 				

NO_CONFIGURE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	sirc

### Enter Default IRC-Server here
IRC_SERVER=	us.undernet.org

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/sirc
	cd ${WRKSRC} ; ( \
		${ECHO} "y" ; \
		${ECHO} "" ; \
		${ECHO} "" ; \
		${ECHO} "" ; \
		${ECHO} "-O3" ; \
		${ECHO} "" ; \
		${ECHO} "${PREFIX}/bin/perl" ; \
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
		echo installing $$i ; \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$i ${PREFIX}/lib/sirc/scripts/$$i ; done

.include "../../mk/bsd.pkg.mk"
