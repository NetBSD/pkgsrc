# $NetBSD: Makefile,v 1.36 2008/01/19 09:16:25 wiz Exp $

DISTNAME=	glunix-release-1-0a
PKGNAME=	glunix-1.0a
PKGREVISION=	2
CATEGORIES=	parallel
MASTER_SITES=	http://now.cs.berkeley.edu/Glunix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://now.cs.berkeley.edu/Glunix/glunix.html
COMMENT=	Global Layer Unix for NOW (Network Of Workstations)

.if exists(/usr/bin/ssh)
SSH=		/usr/bin/ssh
.else
DEPENDS+=	{openssh-[0-9]*,ssh{,6}-1.2.27*}:../../security/openssh
SSH=		${LOCALBASE}/bin/ssh
.endif

WRKSRC=		${WRKDIR}
USE_TOOLS+=	gmake perl
INTERACTIVE_STAGE=	fetch
NO_MTREE=	yes

NOW_ROOT=	${LOCALBASE}/now
MESSAGE_SUBST+=	NOW_ROOT=${NOW_ROOT}

.include "../../mk/endian.mk"
.if (${MACHINE_ENDIAN} == "little")
FLAGS+=-DL_ENDIAN
.endif

MAKE_ENV+= OPSYS=${OPSYS:Q} ARCH=${MACHINE_ARCH:Q} NOW_ROOT=${NOW_ROOT:Q}
MAKE_ENV+= PORTSDIR=${PKGDIR:Q} WRKDIR=${WRKDIR:Q} FLAGS=${FLAGS:Q}
MAKE_ENV+= SSH=${SSH:Q}

PKG_GROUPS=		glunix
PKG_USERS=		glunix:glunix
PKG_SHELL.glunix=	${NOW_ROOT}/bin/glush
USERGROUP_PHASE=	configure

PKG_SHELL=		${NOW_ROOT}/bin/glush

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
		${MV} -f progs/glush/Makefile progs/glush/Makefile.input && \
		${SED} -e 's|%%%PLAT%%%|${MACHINE_ARCH}-NetBSD-tcp|'	\
			progs/glush/Makefile.input > progs/glush/Makefile

pre-configure:
	${CP} ${FILESDIR}/Makefile-2 ${WRKSRC}/Makefile

post-install:
	${LN} -s libglunix.so.1.0 ${PREFIX}/now/lib/libglunix.so.1
	${LN} -s libglunix.so.1.0 ${PREFIX}/now/lib/libglunix.so
	${TOUCH} ${NOW_ROOT}/lib/${MACHINE_ARCH}-${OPSYS}-tcp/.keepme

.include "../../mk/bsd.pkg.mk"
