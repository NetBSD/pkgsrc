# $NetBSD: Makefile,v 1.14 2017/08/01 17:40:13 wiz Exp $
#

DISTNAME=	asr.pages
PKGNAME=	asr-manpages-20000406
CATEGORIES=	misc
MASTER_SITES=	# on ftp.NetBSD.org
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://web.archive.org/web/2/www.winternet.com/~eric/sysadmin/manpages.html
COMMENT=	Distribution of alt.sysadmin.recovery man page

NO_CONFIGURE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	${PKGNAME_NOREV}
INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man2 ${PKGMANDIR}/man3 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

do-install:
	${INSTALL_MAN} ${WRKDIR}/bosskill.8	${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/c.1		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/chastise.3	${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKDIR}/ctluser.8	${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/guru.8		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/knife.8	${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/lart.1m	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/lart.1
	${INSTALL_MAN} ${WRKDIR}/luser.8	${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/normality.5	${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKDIR}/nuke.8		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/people.2	${DESTDIR}${PREFIX}/${PKGMANDIR}/man2
	${INSTALL_MAN} ${WRKDIR}/pmsd.8		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/rtfm.1		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/slave.1	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/sysadmin.1	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/think.1	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/whack.1	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
