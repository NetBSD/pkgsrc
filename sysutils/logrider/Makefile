# $NetBSD: Makefile,v 1.2 2019/10/26 12:28:50 rillig Exp $
#

DISTNAME=	logrider-0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://ilya-evseev.narod.ru/posix/logrider/
EXTRACT_SUFX=	.zip

MAINTAINER=	francksys@free.fr
HOMEPAGE=	http://ilya-evseev.narod.ru/posix/logrider/
COMMENT=	Monitor system logs for alerts
LICENSE=	gnu-gpl-v2

NO_CHECKSUM=	yes
EXTRACT_DIR=	${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	# none

NO_BUILD=	YES
USE_TOOLS+=	bash
REPLACE_BASH=	logrider.sh logtail.sh
PATCH_STRIP=	-p1

SUBST_CLASSES+=		dirs
SUBST_STAGE.dirs=	post-extract
SUBST_MESSAGE.dirs=	Replacing directories
SUBST_FILES.dirs=	logrider.conf logrider.sh
SUBST_SED.dirs=		-E
SUBST_SED.dirs+=	-e 's|CONF_DIR(:?)=/etc|CONF_DIR\1=${PKG_SYSCONFDIR}|'
SUBST_SED.dirs+=	-e 's|LOGTAIL(:?)=/usr|LOGTAIL\1=${PREFIX}|'

BUILD_DEFS+=		VARBASE
EGDIR=			${PREFIX}/share/examples/logrider
INSTALLATION_DIRS=	bin ${EGDIR} ${EGDIR}/violations_ignore
OWN_DIRS=		${PKG_SYSCONFDIR}/logrider ${PKG_SYSCONFDIR}/logrider/violations_ignore ${VARBASE}/lib/logrider

.for file in logrider.conf hacking ignore violations
CONF_FILES+=	${EGDIR}/${file} ${PKG_SYSCONFDIR}/logrider/${file}
.endfor
.for file in cvspserver ftp misc nsfbackup postfix drweb-postfix microbackup named pam sshd
CONF_FILES+=	${EGDIR}/violations_ignore/${file} ${PKG_SYSCONFDIR}/logrider/violations_ignore/${file}
.endfor

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} logtail.sh logrider.sh ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} ignore logrider.conf hacking violations ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/violations_ignore && ${INSTALL_DATA} * ${DESTDIR}${EGDIR}/violations_ignore

.include "../../mk/bsd.pkg.mk"
