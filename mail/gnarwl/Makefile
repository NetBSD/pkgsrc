# $NetBSD: Makefile,v 1.5 2016/03/05 11:28:48 jperkin Exp $

DISTNAME=	gnarwl-3.6
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.onyxbits.de/sites/default/files/upload_cck/node/526/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.onyxbits.de/sites/default/files/upload_cck/node/526/
COMMENT=	LDAP based mail autoresponder
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# data/Makefile depends on legacy rule execution order
MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake groff

GNARWL_LIBS=	-L${BUILDLINK_PREFIX.openldap}/lib	\
		-W,-lR${BUILDLINK_PREFIX.openldap}/lib	\
		-L${BUILDLINK_PREFIX.gdbm}/lib 		\
		-W,-lR${BUILDLINK_PREFIX.gdbm}/lib
CONFIGURE_ENV+=	LDFLAGS=${GNARWL_LIBS:Q}
CONFIGURE_ARGS+=--with-homedir=${GNARWL_HOME}

LDFLAGS.SunOS+=	-liconv

GNARWL_USER?=	gnarwl
GNARWL_GROUP?=	gnarwl
GNARWL_HOME?=	${VARBASE}/gnarwl
BUILD_DEFS+=	GNARWL_USER GNARWL_GROUP 
PKG_GROUPS+=	${GNARWL_GROUP}
PKG_USERS+=	${GNARWL_USER}:${GNARWL_GROUP}
PKG_HOME.gnarwl=${GNARWL_HOME}

GNARWL_MANDIR=		${DESTDIR}${PREFIX}/${PKGMANDIR}

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_MAN_DIR} ${GNARWL_MANDIR}/man8
	${INSTALL_PROGRAM} ${WRKSRC}/src/gnarwl ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/damnit ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/data/badheaders.txt ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/data/blacklist.txt ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/data/footer.txt ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/data/header.txt ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/data/gnarwl.cfg ${DESTDIR}${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/damnit.man ${GNARWL_MANDIR}/man8/damnit.8
	${INSTALL_MAN} ${WRKSRC}/doc/gnarwl.man ${GNARWL_MANDIR}/man8/gnarwl.8

EGDIR=		${PREFIX}/share/examples/gnarwl
EGFILES=	badheaders.txt blacklist.txt footer.txt header.txt gnarwl.cfg	

.for files in ${EGFILES}
CONF_FILES+=            ${EGDIR}/${files} ${PKG_SYSCONFDIR}/${files}
.endfor

MAKE_DIRS_PERMS+=${GNARWL_HOME} ${GNARWL_USER} ${GNARWL_GROUP} 0750
SPECIAL_PERMS+=${PREFIX}/bin/gnarwl ${GNARWL_USER} ${GNARWL_GROUP} 04555

.include "../../mk/dlopen.builtin.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
