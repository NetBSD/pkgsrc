# $NetBSD: Makefile,v 1.25 2012/12/14 23:46:28 marino Exp $

DISTNAME=	sirc-2.211
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	http://www.iagora.com/~espel/sirc/
DISTFILES=	${DEFAULT_DISTFILES} \
		${SIRC_SCRIPTS}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iagora.com/~espel/sirc/sirc.html
COMMENT=	IRC client written and programmable in perl

DEPENDS+=	p5-Socket6>=0.07:../../net/p5-Socket6

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# supports IPv6 (actually, AF-independent)
BUILD_DEFS+=	IPV6_READY

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
USE_TOOLS+=	perl:run
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

.for script in ${SIRC_SCRIPTS}
SITES.${script:T:S/=/--/}?= ${MASTER_SITES:=scripts/}
.endfor

NO_BUILD=	yes
DIST_SUBDIR=	sirc

REPLACE_PERL+=	dsirc

.include "../../mk/bsd.prefs.mk"
.if defined(DEFAULT_IRC_SERVER)
IRC_SERVER=	${DEFAULT_IRC_SERVER}
.else
IRC_SERVER=	us.undernet.org
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 lib/sirc/scripts

do-install:
	cd ${WRKSRC} ; ( \
		${ECHO} "y" ; \
		${ECHO} "" ; \
		${ECHO} "" ; \
		${ECHO} "" ; \
		${ECHO} "-O3" ; \
		${ECHO} "" ; \
		${ECHO} "${PERL5}" ; \
		${ECHO} "${DESTDIR}${PREFIX}/bin" ; \
		${ECHO} "y" ; \
		${ECHO} "${DESTDIR}${PREFIX}/lib/sirc" ; \
		${ECHO} "y" ; \
		${ECHO} "n" ; \
		${ECHO} "${DESTDIR}${PREFIX}/${PKGMANDIR}/man1" ; \
		${ECHO} "${IRC_SERVER}" ; \
		${ECHO} "" ; \
	) | ./install
	for i in ${SIRC_SCRIPTS} ; do \
		${ECHO} installing $$i ; \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$i ${DESTDIR}${PREFIX}/lib/sirc/scripts/$$i ; done

.include "../../mk/bsd.pkg.mk"
