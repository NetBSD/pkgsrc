# $NetBSD: Makefile,v 1.2 1998/11/16 21:02:20 agc Exp $

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

.if (${MACHINE} == "i386")
FLAGS= "-m486 -DL_ENDIAN"
.endif

MAKE_ENV+= OPSYS=${OPSYS} ARCH=${MACHINE} NOW_ROOT=${NOW_ROOT}
MAKE_ENV+= PORTSDIR=${PKGDIR} WRKDIR=${WRKDIR} FLAGS=${FLAGS}

SCRIPTS_ENV+= ARCH=${MACHINE} RM=${RM} NOW_ROOT=${NOW_ROOT}

# the glunix group needs to exist before building.
pre-configure:
	${CP} ${FILESDIR}/Makefile-2 ${WRKSRC}/Makefile
	@addgroup=`${AWK} -F: 'BEGIN { found = gid = 0; }		\
		$$1 == "glunix" { found = 1; exit 0; }			\
		$$1 != "glunix" && $$1 != "nogroup" { if ($$3 > gid) { gid = $$3; } } \
		END { if (found) { printf("--exists--"); } else { printf("glunix:*:%d:\n", gid + 1); }}' /etc/group`;\
	if [ "$$addgroup" != "--exists--" ]; then			\
		${ECHO} "Adding group $$addgroup";			\
		${ECHO} "$$addgroup" >> /etc/group;			\
	fi

pre-install:
	${SED} -e 's|\$${NOW_ROOT}|${NOW_ROOT}|g' ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}
	@${ECHO} "updating /etc/shells";
	${CP} /etc/shells /etc/shells.bak;
	( ${GREP} -v ${NOW_ROOT}/bin/glush /etc/shells.bak;		\
		${ECHO} ${NOW_ROOT}/bin/glush				\
	) >/etc/shells
	-${LOCALBASE}/sbin/addnerd -g glunix -s ${NOW_ROOT}/bin/glush glunix

.include "../../mk/bsd.pkg.mk"
