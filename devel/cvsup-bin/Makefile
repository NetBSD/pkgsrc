# $NetBSD: Makefile,v 1.17 2017/08/01 14:58:55 wiz Exp $

DISTNAME=	cvsup-static-16.1.h
PKGNAME=	${DISTNAME:C/static/bin/}
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://motoyuki.bsdclub.org/data/NetBSD/CVSup/i386/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://people.freebsd.org/~jdp/
COMMENT=	Daemon and client for cvsup

CONFLICTS=	cvsup-[0-9]* cvsup-gui-[0-9]*

EMUL_PLATFORMS=		netbsd-i386
EMUL_REQD=		netbsd>=1.5

# XXX Remove the following line on the next update; see PR 25255 for details
DIST_SUBDIR=		cvsup-i386-1.6

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
BUILD_DIRS=		# empty

AUTO_MKDIRS=			yes

do-install:
	cd ${WRKSRC} && for i in cvpasswd cvsup ; do \
		${INSTALL_PROGRAM} bin/$$i ${DESTDIR}${PREFIX}/bin; \
	done
	cd ${WRKSRC} && for i in cvsupd; do \
		${INSTALL_PROGRAM} sbin/$$i ${DESTDIR}${PREFIX}/sbin; \
	done
	cd ${WRKSRC} && for i in cvpasswd.1 cvsup.1; do \
		${INSTALL_MAN} man/man1/$$i \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	done
	cd ${WRKSRC} && for i in cvsupd.8; do \
		${INSTALL_MAN} man/man8/$$i \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man8; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cvsup
	${INSTALL_DATA} ${WRKSRC}/share/doc/cvsup/License \
		${DESTDIR}${PREFIX}/share/doc/cvsup
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/cvsup
	${INSTALL_DATA} ${FILESDIR}/supfile* \
		${DESTDIR}${PREFIX}/share/examples/cvsup

.include "../../mk/bsd.pkg.mk"
