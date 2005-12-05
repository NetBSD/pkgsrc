# $NetBSD: Makefile,v 1.6 2005/12/05 20:50:38 rillig Exp $
#

DISTNAME=	asr.pages
PKGNAME=	asr-manpages-20000406
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.winternet.com/users/eric/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.winternet.com/~eric/sysadmin/manpages.html
COMMENT=	alt.sysadmin.recovery man page distribution

NO_CONFIGURE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	${PKGNAME_NOREV}
INSTALLATION_DIRS=	man/man1 man/man2 man/man3 man5 man/man8

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
