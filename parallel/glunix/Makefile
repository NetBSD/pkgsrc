# $NetBSD: Makefile,v 1.15 2000/10/21 22:52:37 wiz Exp $

DISTNAME=	glunix-release-1-0a
PKGNAME=	glunix-1.0a
CATEGORIES=	parallel
MASTER_SITES=	http://now.cs.berkeley.edu/Glunix/ \
		http://www.inficad.com/~garbled/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} makedepend${EXTRACT_SUFX}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://now.cs.berkeley.edu/Glunix/glunix.html

.if exists(/usr/bin/ssh)
SSH=		/usr/bin/ssh
.else
DEPENDS+=	{openssh-*,ssh{,6}-1.2.27}:../../security/ssh
SSH=		${LOCALBASE}/bin/ssh
.endif

USE_GMAKE=	yes
USE_PERL5=	yes
IS_INTERACTIVE= yes
NO_MTREE=	yes
NO_WRKSUBDIR=	yes

MESSAGE_FILE=	${WRKDIR}/MESSAGE

NOW_ROOT=	${LOCALBASE}/now

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

# the glunix group needs to exist before building.
pre-configure:
	${CP} ${FILESDIR}/Makefile-2 ${WRKSRC}/Makefile
	@if `${GROUP_CMD} info -e glunix`; then				\
		${ECHO} Group \'glunix\' already exists.;		\
	else								\
		${GROUP_CMD} add glunix;				\
	fi

pre-install:
	${SED} -e 's|\$${NOW_ROOT}|${NOW_ROOT}|g' ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}
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
