# $NetBSD: Makefile,v 1.8 2000/12/14 19:45:49 tv Exp $
#

DISTNAME=	plex86-20001214.2
PKGNAME=	plex86-0.20001214.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.plex86.org/

WRKSRC=		${WRKDIR}/plex86
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-NetBSD \
		--with-netbsd-source=${BSDSRCDIR}/sys
USE_GMAKE=	yes
NO_PKG_REGISTER=	yes	# ONLY until we really install files!!!
NO_PACKAGE=	Incomplete	# ONLY until we really install files!!!

BSDSRCDIR?=	/nonexistent	# to override <bsd.own.mk>, MUST be
                                # set this way BEFORE bsd.prefs.mk
.include "../../mk/bsd.prefs.mk"

pre-extract:
.if ${BSDSRCDIR} == "/nonexistent"
	@${ECHO_MSG} "Please set BSDSRCDIR in /etc/mk.conf."
	@${FALSE}
.endif
.if !exists(${BSDSRCDIR}/sys/sys/param.h)
	@${ECHO_MSG} "Need a kernel source tree in ${BSDSRCDIR}/sys."
	@${ECHO_MSG} "(Or set BSDSRCDIR correctly in /etc/mk.conf.)"
	@${FALSE}
.endif

do-install:
	@${CAT} ${MESSAGE_FILE}
	@${ECHO_MSG} Package NOT recorded as installed!
	@# Remove the NO_PKG_REGISTER/NO_PACKAGE above if this does something!!!

.include "../../mk/bsd.pkg.mk"
