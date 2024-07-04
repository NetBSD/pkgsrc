# $NetBSD: Makefile,v 1.2 2024/07/04 20:18:37 cheusov Exp $

DISTNAME=	mm-0.96.0.14
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/vins/dists/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.kermitproject.org/mm/
COMMENT=	UNIX reimplementation of the TOPS-20 MM program
LICENSE=	modified-bsd

USE_TOOLS+=	pax m4

MAKE_FLAGS+=	OPT=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	LOCLIB=${DESTDIR}${PREFIX}/lib/mm

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_FILES.paths+=	config.h pathnames.h
SUBST_FILES.paths+=	regex-0.12/configure
SUBST_SED.paths=	-e 's|/usr/local|${PREFIX}|'

SETUID_ROOT_PERMS=	${REAL_ROOT_USER} daemon 2551
SPECIAL_PERMS+=		lib/mm/movemail  ${SETUID_ROOT_PERMS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == Linux
TARGET:=	${LOWER_OPSYS}
.elif ${OPSYS} == Darwin
TARGET:=	macosx
.elif ${OPSYS} == SunOS
.  if ${OPSYS_VERSION} <= 051000
TARGET:=	solaris10
.  else
TARGET:=	solaris-gcc
.  endif
.endif

EGDIR=	${PREFIX}/share/examples/${PKGBASE}
DOCDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS+=	bin lib ${EGDIR} ${DOCDOR}

WRKSRC=	${WRKDIR}/mm/mm

post-extract:
	${RUN}${CHMOD} +x ${WRKSRC}/regex-0.12/configure

pre-build:
	${RUN}cd ${WRKDIR}/mm/ccmd && ${SETENV} ${MAKE_ENV}	\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${TARGET}

do-build:
	${RUN}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${TARGET}

pre-install:
	${RUN}cd ${WRKDIR}/mm/ccmd && ${SETENV} ${MAKE_ENV} 	\
		${INSTALL_ENV} ${MAKE_PROGRAM}			\
		prefix=${DESTDIR}${PREFIX} install

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sys-prof			\
		${DESTDIR}/${PREFIX}/bin/mm-sysprof
	${RUN}cd ${WRKDIR}/mm/docs && 				\
		${PAX} -rw . ${DESTDIR}${DOCDIR}
.for f in samples/*
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${EGDIR}
.endfor
	${INSTALL_DATA} ${FILESDIR}/sample-mm-conf ${DESTDIR}${EGDIR}
	#Fix files permissions.
	${RUN}${CHMOD} -x ${DESTDIR}${PREFIX}/lib/libccmd.a
	${RUN}${CHMOD} g-w ${DESTDIR}${PREFIX}/lib/mm/mmail.el

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
