# $NetBSD: Makefile,v 1.3 2001/06/11 04:59:58 jtb Exp $

DISTNAME=	sarah-0.4b
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.conundrum.com/pub/sarah/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	Syslog automated Rotation and Archive Handler

LICENSE=	limited-redistribution
RESTRICTED=	"Do not redistribute"
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

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
