# $NetBSD: Makefile,v 1.1.1.1 2001/03/13 19:49:01 zuntum Exp $

DISTNAME=	sarah-0.4b
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.conundrum.com/pub/sarah/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	Syslog automated Rotation and Archive Handler

USE_PERL5=	YES
NO_BUILD=	YES

do-configure:
	${SED}	-e "s,/usr/local,${PREFIX},g"				\
		-e "s,/usr/bin/perl,${LOCALBASE}/bin/perl,g"		\
		-e "s,syslog.pid,syslogd.pid,g"				\
		${WRKSRC}/sarah > ${WRKSRC}/sarah.done
	${MV} ${WRKSRC}/sarah.done ${WRKSRC}/sarah
	${SED}	-e "s,/usr/local,${PREFIX},g"				\
		-e "s,syslog.pid,syslogd.pid,g"				\
		${WRKSRC}/sarah.1 > ${WRKSRC}/sarah.1.done
	${MV} ${WRKSRC}/sarah.1.done ${WRKSRC}/sarah.1

do-install:
	cd ${WRKSRC} &&							\
		${INSTALL_SCRIPT} sarah ${PREFIX}/bin &&		\
		${INSTALL_DATA} sarah.conf.sample ${PREFIX}/etc &&	\
		${INSTALL_MAN} sarah.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sarah
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/CHANGES		\
		${PREFIX}/share/doc/sarah

.include "../../mk/bsd.pkg.mk"
