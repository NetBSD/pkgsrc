# $NetBSD: Makefile,v 1.8 2007/01/07 09:14:00 rillig Exp $
#

DISTNAME=	asr.pages
PKGNAME=	asr-manpages-20000406
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.winternet.com/users/eric/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.winternet.com/~eric/sysadmin/manpages.html
COMMENT=	alt.sysadmin.recovery man page distribution

NO_CONFIGURE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	${PKGNAME_NOREV}
INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man2 ${PKGMANDIR}/man3 man5 ${PKGMANDIR}/man8

do-install:
	${INSTALL_MAN} ${WRKDIR}/bosskill.8	${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/c.1		${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/chastise.3	${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKDIR}/ctluser.8	${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/guru.8		${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/knife.8	${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/lart.1m	${PREFIX}/${PKGMANDIR}/man1/lart.1
	${INSTALL_MAN} ${WRKDIR}/luser.8	${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/normality.5	${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKDIR}/nuke.8		${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/people.2	${PREFIX}/${PKGMANDIR}/man2
	${INSTALL_MAN} ${WRKDIR}/pmsd.8		${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKDIR}/rtfm.1		${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/slave.1	${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/sysadmin.1	${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/think.1	${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/whack.1	${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
