# $NetBSD: Makefile,v 1.3 2005/02/18 22:12:50 jlam Exp $

DISTNAME=	courier-0.48.2
PKGNAME=	${DISTNAME:S/-/-maildir-/}
PKGBASE=	${PKGNAME:C/-[^-]*$//}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@NetBSD.org
COMMENT=	Courier maildir utilities
HOMEPAGE=	http://www.courier-mta.org/

CONFLICTS=	courier-maildirmake-[0-9]*

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_PERL5=		yes
PERL5_REQD+=		5.8.0

.include "Makefile.common"

# This package doesn't need to depend on courier-authlib -- just fake
# out the top-level configure script that thinks it needs
# courierauthconfig.
#
CONFIGURE_ENV+=		ac_cv_path_COURIERAUTHCONFIG=${TRUE:Q}

# These are files required by the Courier configure scripts.
WRKSRC_FILES=		config.guess config.sub configure depcomp	\
			install-sh ltmain.sh missing sysconftool
WRKSRC_FILES+=		Makefile.in courier.spec.in courier.sysvinit.in	\
			dbobj.h.in dbobj.config.in courier/courier.c

# These are subdirectories containing libraries used by courier-maildir.
#
WRKSRC_SUBDIRS=		bdbobj numlib liblock unicode rfc822 maildir

EXTRACT_ELEMENTS=	${WRKSRC_FILES:S/^/${DISTNAME}\//}
EXTRACT_ELEMENTS+=	${WRKSRC_SUBDIRS:S/^/${DISTNAME}\//}

BUILD_DIRS=		${WRKSRC_SUBDIRS:S/^/${WRKSRC}\//}
INSTALLATION_DIRS=	bin man/man1 man/man5 man/man5 man/man7 man/man8 sbin

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
OWN_DIRS=		${PKG_SYSCONFDIR}/shared
OWN_DIRS+=		${PKG_SYSCONFDIR}/shared.tmp
CONF_FILES=		${EGDIR}/quotawarnmsg ${PKG_SYSCONFDIR}/quotawarnmsg
CONF_FILES_PERMS=	${EGDIR}/sharedindexupdate			\
			${PKG_SYSCONFDIR}/sharedindexupdate		\
			${ROOT_USER} ${ROOT_GROUP} 0755

post-build:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/sharedindexupdate.sh	\
		> ${WRKDIR}/sharedindexupdate.sh

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/maildir/deliverquota		\
		${PREFIX}/bin/deliverquota
	${INSTALL_PROGRAM} ${WRKSRC}/maildir/maildiracl			\
		${PREFIX}/bin/courier-maildiracl
	${INSTALL_PROGRAM} ${WRKSRC}/maildir/maildirkw			\
		${PREFIX}/bin/courier-maildirkw
	${INSTALL_PROGRAM} ${WRKSRC}/maildir/maildirmake		\
		${PREFIX}/bin/courier-maildirmake
	${INSTALL_MAN} ${WRKSRC}/maildir/maildiracl.1			\
		${PREFIX}/man/man1/courier-maildiracl.1
	${INSTALL_MAN} ${WRKSRC}/maildir/maildirkw.1			\
		${PREFIX}/man/man1/courier-maildirkw.1
	${INSTALL_MAN} ${WRKSRC}/maildir/maildirmake.1			\
		${PREFIX}/man/man1/courier-maildirmake.1
	${INSTALL_MAN} ${WRKSRC}/maildir/maildir.5			\
		${PREFIX}/man/man5/courier-maildir.5
	${INSTALL_MAN} ${WRKSRC}/maildir/maildirquota.7			\
		${PREFIX}/man/man7/maildirquota.7
	${INSTALL_MAN} ${WRKSRC}/maildir/deliverquota.8			\
		${PREFIX}/man/man8/deliverquota.8
	${INSTALL_DATA} ${WRKSRC}/maildir/quotawarnmsg			\
		${EGDIR}/quotawarnmsg
	${INSTALL_SCRIPT} ${WRKSRC}/maildir/sharedindexinstall		\
		${PREFIX}/sbin/sharedindexinstall
	${INSTALL_SCRIPT} ${WRKSRC}/maildir/sharedindexsplit		\
		${PREFIX}/sbin/sharedindexsplit
	${INSTALL_SCRIPT} ${WRKDIR}/sharedindexupdate.sh		\
		${EGDIR}/sharedindexupdate
	${INSTALL_DATA} ${WRKSRC}/maildir/README.imapkeywords.html	\
		${DOCDIR}/README.imapkeywords.html
	${INSTALL_DATA} ${WRKSRC}/maildir/README.maildirfilter.html	\
		${DOCDIR}/README.maildirfilter.html
	${INSTALL_DATA} ${WRKSRC}/maildir/README.maildirquota.html	\
		${DOCDIR}/README.maildirquota.html
	${INSTALL_DATA} ${WRKSRC}/maildir/README.sharedfolders.html	\
		${DOCDIR}/README.sharedfolders.html

.include "../../mk/bsd.pkg.mk"
