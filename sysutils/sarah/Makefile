# $NetBSD: Makefile,v 1.8 2005/06/17 03:50:35 jlam Exp $

DISTNAME=	sarah-0.7b
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.conundrum.com/pub/sarah/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Syslog automated Rotation and Archive Handler

LICENSE=	limited-redistribution
RESTRICTED=	"Do not redistribute"
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

USE_PERL5=	YES
REPLACE_PERL=	sarah
NO_BUILD=	YES

INSTALLATION_DIRS=	bin man/man1

post-patch:
	${SED}	-e "s,/usr/local,${PREFIX},g"				\
		-e "s,syslog.pid,syslogd.pid,g"				\
		${WRKSRC}/sarah > ${WRKSRC}/sarah.done
	${MV} ${WRKSRC}/sarah.done ${WRKSRC}/sarah
	${SED}	-e "s,/usr/local,${PREFIX},g"				\
		-e "s,syslog.pid,syslogd.pid,g"				\
		${WRKSRC}/sarah.1 > ${WRKSRC}/sarah.1.done
	${MV} ${WRKSRC}/sarah.1.done ${WRKSRC}/sarah.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sarah ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sarah
	${INSTALL_DATA} ${WRKSRC}/sarah.conf.sample ${PREFIX}/share/examples/sarah
	${INSTALL_MAN} ${WRKSRC}/sarah.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sarah
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sarah

.include "../../mk/bsd.pkg.mk"
