# $NetBSD: Makefile,v 1.1.1.1 1998/10/21 19:59:29 garbled Exp $

DISTNAME=	glunix-release-1-0a
PKGNAME=	glunix-1.0a
CATEGORIES=	parallel
MASTER_SITES=	http://now.cs.berkeley.edu/Glunix/ \
		http://www.inficad.com/~garbled/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} makedepend${EXTRACT_SUFX}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://now.cs.berkeley.edu/Glunix/glunix.html

DEPENDS+=	ssh-1.2.26:../../security/ssh
DEPENDS+=	addnerd-1.6:../../sysutils/addnerd

USE_GMAKE=	yes
USE_PERL5=	yes
IS_INTERACTIVE= yes
NO_MTREE=	yes
NO_WRKSUBDIR=	yes

MESSAGE_FILE=	${WRKDIR}/MESSAGE

NOW_ROOT=	${LOCALBASE}/now

MACHINE_ARCH!=	uname -m

.if (${MACHINE_ARCH} == "i386")
FLAGS= "-m486 -DL_ENDIAN"
.endif

MAKE_ENV+= OPSYS=${OPSYS} ARCH=${MACHINE_ARCH} NOW_ROOT=${NOW_ROOT}
MAKE_ENV+= PORTSDIR=${PKGDIR} WRKDIR=${WRKDIR} FLAGS=${FLAGS}

SCRIPTS_ENV+= ARCH=${MACHINE_ARCH} RM=${RM} NOW_ROOT=${NOW_ROOT}

pre-configure:
	${CP} ${FILESDIR}/Makefile-2 ${WRKSRC}/Makefile

pre-install:
	${SED} -e 's|\$${NOW_ROOT}|${NOW_ROOT}|g' ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}
	@${ECHO} "updating /etc/shells";
	${CP} /etc/shells /etc/shells.bak;
	( ${GREP} -v ${NOW_ROOT}/bin/glush /etc/shells.bak;		\
		${ECHO} ${NOW_ROOT}/bin/glush				\
	) >/etc/shells
	-${LOCALBASE}/sbin/addnerd -g glunix -s ${NOW_ROOT}/bin/glush glunix

.include "../../mk/bsd.pkg.mk"
