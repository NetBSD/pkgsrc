# $NetBSD: Makefile,v 1.1.1.1 2000/12/14 04:25:52 hubertf Exp $
#

DISTNAME=	plex86
PKGNAME=	plex86-0.20001214
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/fvdl/
DISTFILES=	plex86-20001214.tgz plex86.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.plex86.org/

BUILD_DEPENDS+=	autoconf:../../devel/autoconf

DIST_SUBDIR=	plex86-20001214
WRKSRC=		${WRKDIR}/plex86
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-NetBSD \
		--with-netbsd-source=/sys
BSDSRCDIR?=	/usr/src
USE_GMAKE=	yes
NO_PKG_REGISTER=	yes	# ONLY until we really install files!!!
NO_PACKAGE=	Incomplete	# ONLY until we really install files!!!

pre-extract:
		@if [ ! -f ${BSDSRCDIR}/sys/sys/param.h ]; then \
			${ECHO_MSG} Need a kernel source tree in ${BSDSRCDIR}/sys ; \
			${ECHO_MSG} "(set BSDSRCDIR accordingly in /etc/mk.conf!)" ; \
			exit 1 ; \
		fi

pre-patch:
		cd ${WRKSRC} ; \
		${PATCH} ${PATCH_ARGS} <${WRKDIR}/plex86.diff
		${CP} ${WRKDIR}/kernel/host-netbsd.c ${WRKSRC}/kernel
		${CP} ${WRKDIR}/misc/netbsd_post.sh ${WRKSRC}/misc

pre-configure:
		cd ${WRKSRC} ; autoconf

do-install:
	@${CAT} ${MESSAGE_FILE}
	@${ECHO_MSG} Package NOT recorded as installed!
	@# Remove the NO_PKG_REGISTER/NO_PACKAGE above if this does something!!!
	@# Remove the NO_PKG_REGISTER/NO_PACKAGE above if this does something!!!
	@# Remove the NO_PKG_REGISTER/NO_PACKAGE above if this does something!!!

.include "../../mk/bsd.pkg.mk"
