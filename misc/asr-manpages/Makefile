# $NetBSD: Makefile,v 1.1.1.1 2000/04/07 02:22:47 hubertf Exp $
#

DISTNAME=	asr.pages
PKGNAME=	asr-manpages-20000406
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.winternet.com/users/eric/
EXTRACT_SUFX=	.tar

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.winternet.com/~eric/sysadmin/manpages.html

NO_CONFIGURE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	${PKGNAME}

do-install:
	${INSTALL_MAN} ${WRKDIR}/bosskill.8	${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/c.1		${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/chastise.3	${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKDIR}/ctluser.8	${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/guru.8		${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/knife.8	${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/lart.1m	${PREFIX}/man/man1/lart.1
	${INSTALL_MAN} ${WRKDIR}/luser.8	${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/normality.5	${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKDIR}/nuke.8		${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/people.2	${PREFIX}/man/man2
	${INSTALL_MAN} ${WRKDIR}/pmsd.8		${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/rtfm.1		${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/slave.1	${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/sysadmin.1	${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/think.1	${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/whack.1	${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
