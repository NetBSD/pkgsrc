# $NetBSD: Makefile,v 1.21 2015/01/17 16:08:00 mef Exp $

DISTNAME=	sarah-0.9.1b
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sarah/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sarah.sourceforge.net/
COMMENT=	Syslog automated Rotation and Archive Handler

USE_TOOLS+=	perl:run
REPLACE_PERL=	sarah
NO_BUILD=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/sarah \
			share/examples/sarah
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
	${INSTALL_SCRIPT} ${WRKSRC}/sarah ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sarah.conf.sample ${DESTDIR}${PREFIX}/share/examples/sarah
	${INSTALL_MAN} ${WRKSRC}/sarah.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/sarah

.include "../../mk/bsd.pkg.mk"
