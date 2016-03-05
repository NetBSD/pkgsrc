# $NetBSD: Makefile,v 1.7 2016/03/05 11:29:27 jperkin Exp $
#

PKGNAME=	stud-0.3p53
PKGREVISION=	6
CATEGORIES=	security
MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	http://github.com/bumptech/stud
COMMENT=	Scalable TLS Unwrapping Daemon
LICENSE=	2-clause-bsd

MASTER_SITES=	http://rohara.fedorapeople.org/stud/
DISTNAME=	bumptech-stud-0.3-51-g0b88039
WRKSRC=		${WRKDIR}/bumptech-stud-0b88039

USE_TOOLS+=		gmake nroff pax:run

BUILD_DEFS+=		STUD_USER STUD_GROUP VARBASE

.include "../../mk/bsd.prefs.mk"

STUD_USER?=		stud
STUD_GROUP?=		stud
# Default file that should contain the X509 certificates PEM file
STUD_CERTS?=		${PKG_SYSCONFDIR}/certs.pem
STUD_HOME?=		${VARBASE}/chroot/stud

PKG_GROUPS?=		${STUD_GROUP}
PKG_USERS?=		${STUD_USER}:${STUD_GROUP}
PKG_GECOS.${STUD_USER}=	stud daemon user
PKG_HOME.${STUD_USER}=	${STUD_HOME}

RCD_SCRIPTS=		stud

EGDIR=			${PREFIX}/share/examples/stud
OWN_DIRS=		${STUD_HOME}
INSTALLATION_DIRS+=	bin ${EGDIR} ${PKGMANDIR}/cat8

FILES_SUBST+=		STUD_HOME=${STUD_HOME:Q}

SUBST_CLASSES+=		studconf
SUBST_STAGE.studconf=	pre-configure
SUBST_FILES.studconf=	stud.conf
SUBST_VARS.studconf=	STUD_USER STUD_GROUP STUD_HOME STUD_CERTS
SUBST_MESSAGE.studconf=	Set default configuration values.

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_FILES.makefile=	Makefile
SUBST_VARS.makefile=	PREFIX
SUBST_MESSAGE.makefile=	Set prefix path.

PKG_SYSCONFSUBDIR=	stud
PKG_SYSCONFDIR_PERMS=	${ROOT_USER} ${STUD_GROUP} 0750
CONF_FILES+=		${EGDIR}/stud.conf ${PKG_SYSCONFDIR}/stud.conf

post-extract:
	${CP} ${FILESDIR}/stud.conf ${WRKSRC}/stud.conf

post-build:
.if !empty(MANINSTALL:Mcatinstall)
	cd ${WRKSRC} && nroff -mdoc stud.8 > stud.cat8
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/stud.conf ${DESTDIR}${EGDIR}/stud.conf
.if !empty(MANINSTALL:Mcatinstall)
.  if defined(CATMAN_SECTION_SUFFIX) && !empty(CATMAN_SECTION_SUFFIX:M[Yy][Ee][Ss])
	${INSTALL_MAN} ${WRKSRC}/stud.cat8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat8/stud.8
.  else
	${INSTALL_MAN} ${WRKSRC}/stud.cat8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat8/stud.0
.  endif
.endif

.include "../../devel/libev/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
