# $NetBSD: Makefile,v 1.4 2000/12/14 15:52:39 tv Exp $
#

DISTNAME=	plex86
PKGNAME=	plex86-0.20001214
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/fvdl/ \
		${MASTER_SITE_LOCAL}
DISTFILES=	plex86-20001214.tgz plex86.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.plex86.org/

BUILD_DEPENDS+=	autoconf:../../devel/autoconf

DIST_SUBDIR=	plex86-20001214
WRKSRC=		${WRKDIR}/plex86
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-NetBSD \
		--with-netbsd-source=/sys
USE_GMAKE=	yes
NO_PKG_REGISTER=	yes	# ONLY until we really install files!!!
NO_PACKAGE=	Incomplete	# ONLY until we really install files!!!

BSDSRCDIR?=	/nonexistent	# (to override <bsd.own.mk>)
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

pre-patch:
	cd ${WRKSRC} && \
		${PATCH} ${PATCH_ARGS} <${WRKDIR}/plex86.diff
	${CP} ${WRKDIR}/kernel/host-netbsd.c ${WRKSRC}/kernel
	${CP} ${WRKDIR}/misc/netbsd_post.sh ${WRKSRC}/misc

pre-configure:
	cd ${WRKSRC} && autoconf

do-install:
	@${CAT} ${MESSAGE_FILE}
	@${ECHO_MSG} Package NOT recorded as installed!
	@# Remove the NO_PKG_REGISTER/NO_PACKAGE above if this does something!!!

.include "../../mk/bsd.pkg.mk"
