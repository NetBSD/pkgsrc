# $NetBSD: Makefile,v 1.24 2002/07/17 13:17:21 agc Exp $

DISTNAME=	glunix-release-1-0a
PKGNAME=	glunix-1.0a
CATEGORIES=	parallel
MASTER_SITES=	http://now.cs.berkeley.edu/Glunix/ \
		http://www.inficad.com/~garbled/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} makedepend${EXTRACT_SUFX}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://now.cs.berkeley.edu/Glunix/glunix.html
COMMENT=	Global Layer Unix for NOW (Network Of Workstations)

.if exists(/usr/bin/ssh)
SSH=		/usr/bin/ssh
.else
DEPENDS+=	{openssh-[0-9]*,ssh{,6}-1.2.27*}:../../security/ssh
SSH=		${LOCALBASE}/bin/ssh
.endif

USE_GMAKE=	yes
USE_PERL5=	yes
INTERACTIVE_STAGE=	fetch
NO_MTREE=	yes
WRKSRC=		${WRKDIR}

NOW_ROOT=	${LOCALBASE}/now
MESSAGE_SUBST+=	NOW_ROOT=${NOW_ROOT}

.if (${MACHINE} == "i386")
FLAGS= "-m486 -DL_ENDIAN"
.endif

MAKE_ENV+= OPSYS=${OPSYS} ARCH=${MACHINE_ARCH} NOW_ROOT=${NOW_ROOT}
MAKE_ENV+= PORTSDIR=${PKGDIR} WRKDIR=${WRKDIR} FLAGS=${FLAGS}
MAKE_ENV+= SSH=${SSH}

SCRIPTS_ENV+= ARCH=${MACHINE_ARCH} RM=${RM} NOW_ROOT=${NOW_ROOT}

.if exists(/usr/sbin/user)
USER_CMD=       /usr/sbin/user
GROUP_CMD=      /usr/sbin/group
.else
DEPENDS+=       user>=20000313:../../sysutils/user
USER_CMD=       ${LOCALBASE}/sbin/user
GROUP_CMD=      ${LOCALBASE}/sbin/group
.endif

.if defined(BATCH)
BATCH_CHECK_DISTFILES=	batch-check-distfiles
.endif

pre-fetch: ${BATCH_CHECK_DISTFILES}
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/pre-fetch

post-patch:
	cd ${WRKSRC};							\
		for f in progs/glupart/glupart.c			\
				progs/glunix/glunix.1			\
				progs/glurun/glurun-wrapper.pl		\
				progs/tools/run_glunix.c 		\
				glunix/src/init/glunix.h; do 		\
			${MV} -f $$f $$f.input &&			\
			${SED} -e 's|%%%NOW_ROOT%%%|${NOW_ROOT}|' $$f.input > $$f; \
		done;							\
		${MV} -f glush/Makefile glush/Makefile.input &&		\
		${SED} -e 's|%%%PLAT%%%|${MACHINE_ARCH}-NetBSD-tcp|'	\
			progs/glush/Makefile.input > progs/glush/Makefile

# the glunix group needs to exist before building.
pre-configure:
	${CP} ${FILESDIR}/Makefile-2 ${WRKSRC}/Makefile
	@if `${GROUP_CMD} info -e glunix`; then				\
		${ECHO} Group \'glunix\' already exists.;		\
	else								\
		${GROUP_CMD} add glunix;				\
	fi

pre-install:
	@${ECHO} "updating /etc/shells";
	${CP} /etc/shells /etc/shells.bak;
	( ${GREP} -v ${NOW_ROOT}/bin/glush /etc/shells.bak;		\
		${ECHO} ${NOW_ROOT}/bin/glush				\
	) >/etc/shells
	@if `${USER_CMD} info -e glunix`; then				\
		${ECHO} User \'glunix\' already exists.;		\
	else								\
		${USER_CMD} add -g glunix -d /nonexistent		\
			-s ${NOW_ROOT}/bin/glush glunix;		\
	fi;

post-install:
	@${TOUCH} ${NOW_ROOT}/lib/${MACHINE_ARCH}-${OPSYS}-tcp/.keepme

.include "../../mk/bsd.pkg.mk"
