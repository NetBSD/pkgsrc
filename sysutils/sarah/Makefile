# $NetBSD: Makefile,v 1.14 2009/05/01 14:52:02 zafer Exp $

DISTNAME=	sarah-0.9.1b
CATEGORIES=	sysutils
MASTER_SITES=	http://prdownloads.sourceforge.net/sarah/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sarah.sourceforge.net/
COMMENT=	Syslog automated Rotation and Archive Handler

USE_TOOLS+=	perl:run
REPLACE_PERL=	sarah
NO_BUILD=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
CONF_FILES+=	${PREFIX}/share/examples/sarah/sarah.conf.sample \
			${PKG_SYSCONFDIR}/sarah.conf

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
	${INSTALL_MAN} ${WRKSRC}/sarah.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sarah
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sarah

.include "../../mk/bsd.pkg.mk"
