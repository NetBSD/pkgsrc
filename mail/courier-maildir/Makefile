# $NetBSD: Makefile,v 1.40 2022/06/28 11:34:19 wiz Exp $

DISTNAME=	courier-${COURIER_VERSION}
PKGNAME=	${DISTNAME:S/-/-maildir-/}
PKGREVISION=	11
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Courier maildir utilities
HOMEPAGE=	https://www.courier-mta.org/

CONFLICTS=	courier-maildirmake-[0-9]*

USE_TOOLS+=		gmake perl:run
USE_LANGUAGES=		c c++

.include "../../mail/courier-mta/Makefile.common"

# This package doesn't need to depend on courier-authlib -- just fake
# out the top-level configure script that thinks it needs
# courierauthconfig.
CONFIGURE_ENV+=		ac_cv_path_COURIERAUTHCONFIG=${TRUE:Q}

# These are files required by the Courier configure scripts.
WRKSRC_FILES=		courier/courier.c config.guess config.sub	\
			configure depcomp install-sh ltmain.sh missing	\
			sysconftool
WRKSRC_FILES+=		Makefile.in courier.spec.in courier.lpspec.in	\
			dbobj.h.in dbobj.config.in courier.service.in	\
			courier.sysvinit.in

# These are subdirectories containing libraries used by courier-maildir.
WRKSRC_SUBDIRS=		bdbobj numlib liblock unicode rfc822 maildir

EXTRACT_ELEMENTS=	${WRKSRC_FILES:S/^/${DISTNAME}\//}
EXTRACT_ELEMENTS+=	${WRKSRC_SUBDIRS:S/^/${DISTNAME}\//}

BUILD_DIRS=		${WRKSRC_SUBDIRS:S/^/${WRKSRC}\//}
INSTALLATION_DIRS=	bin			sbin			\
			${PKGMANDIR}/man1	${PKGMANDIR}/man7	\
			${PKGMANDIR}/man5	${PKGMANDIR}/man8	\
			${DOCDIR}		${EGDIR}

REQD_DIRS=		${DOCDIR} ${EGDIR}
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR}/shared			\
			${COURIER_DIR_PERMS}
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/shared.tmp			\
			${COURIER_DIR_PERMS}
CONF_FILES_PERMS+=	${EGDIR}/quotawarnmsg				\
			${PKG_SYSCONFDIR}/quotawarnmsg			\
			${COURIER_FILE_PERMS}
CONF_FILES_PERMS+=	${EGDIR}/sharedindexupdate			\
			${PKG_SYSCONFDIR}/sharedindexupdate		\
			${COURIER_SCRIPT_PERMS}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/sharedindexupdate.sh
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_VARS.paths+=	MKDIR
SUBST_VARS.paths+=	RM
SUBST_VARS.paths+=	SH
SUBST_VARS.paths+=	TEST
SUBST_STAGE.paths=	pre-configure

post-extract:
	${CP} ${FILESDIR}/sharedindexupdate.sh ${WRKDIR}/sharedindexupdate.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/maildir/deliverquota		\
		${DESTDIR}${PREFIX}/bin/deliverquota
	${INSTALL_PROGRAM} ${WRKSRC}/maildir/maildiracl			\
		${DESTDIR}${PREFIX}/bin/courier-maildiracl
	${INSTALL_PROGRAM} ${WRKSRC}/maildir/maildirkw			\
		${DESTDIR}${PREFIX}/bin/courier-maildirkw
	${INSTALL_PROGRAM} ${WRKSRC}/maildir/maildirmake		\
		${DESTDIR}${PREFIX}/bin/courier-maildirmake
	${INSTALL_MAN} ${WRKSRC}/maildir/maildiracl.1			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/courier-maildiracl.1
	${INSTALL_MAN} ${WRKSRC}/maildir/maildirkw.1			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/courier-maildirkw.1
	${INSTALL_MAN} ${WRKSRC}/maildir/maildirmake.1			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/courier-maildirmake.1
	${INSTALL_MAN} ${WRKSRC}/maildir/maildir.5			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/courier-maildir.5
	${INSTALL_MAN} ${WRKSRC}/maildir/maildirquota.7			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/maildirquota.7
	${INSTALL_MAN} ${WRKSRC}/maildir/deliverquota.8			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/deliverquota.8
	${INSTALL_DATA} ${WRKSRC}/maildir/quotawarnmsg			\
		${DESTDIR}${EGDIR}/quotawarnmsg
	${INSTALL_SCRIPT} ${WRKSRC}/maildir/sharedindexinstall		\
		${DESTDIR}${PREFIX}/sbin/sharedindexinstall
	${INSTALL_SCRIPT} ${WRKSRC}/maildir/sharedindexsplit		\
		${DESTDIR}${PREFIX}/sbin/sharedindexsplit
	${INSTALL_SCRIPT} ${WRKDIR}/sharedindexupdate.sh		\
		${DESTDIR}${EGDIR}/sharedindexupdate
	grep "^${DOCDIR:S/${PREFIX}\///}" ${PKGDIR}/PLIST |		\
	while read file; do						\
		src=${WRKSRC}/maildir/`basename $$file`;		\
		dst=${DESTDIR}${PREFIX}"/$$file";			\
		${INSTALL_DATA} "$$src" "$$dst";			\
	done

.include "../../mk/bsd.pkg.mk"
