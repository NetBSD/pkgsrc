# $NetBSD: Makefile,v 1.8 2001/11/28 05:20:42 jlam Exp $

DISTNAME=	sirc-2.211
PKGNAME=	sirc-2.211nb1
CATEGORIES=	chat
MASTER_SITES=	http://www.iagora.com/~espel/sirc/ \
		http://www.iagora.com/~espel/sirc/scripts/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}	\
		${SIRC_SCRIPTS}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.iagora.com/~espel/sirc/sirc.html
COMMENT=	IRC client written and programmable in perl

DEPENDS+=	p5-Socket6>=0.07:../../net/p5-Socket6

# supports IPv6 (actually, af independent)
BUILD_DEFS+=	USE_INET6

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

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
