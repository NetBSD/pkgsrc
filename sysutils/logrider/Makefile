# $NetBSD: Makefile,v 1.1 2013/05/07 08:49:28 wiz Exp $
#

DISTNAME=	logrider-0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://ilya-evseev.narod.ru/posix/logrider/
EXTRACT_SUFX=	.zip

MAINTAINER=     francksys@free.fr
HOMEPAGE=	http://ilya-evseev.narod.ru/posix/logrider/
COMMENT=	Monitor system logs for alerts
LICENSE=	gnu-gpl-v2

NO_CHECKSUM=yes
EXTRACT_DIR=	${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	# none

NO_BUILD=	YES
USE_TOOLS+=	bash
REPLACE_BASH=	logrider.sh logtail.sh
PATCH_STRIP=    -p1

SUBST_CLASSES+=               config_dir
SUBST_STAGE.config_dir=      post-extract
SUBST_MESSAGE.config_dir=    Replacing directories
SUBST_FILES.config_dir=      logrider.conf logrider.sh
SUBST_SED.config_dir=        -E -e 's|CONF_DIR(:?)=/etc|CONF_DIR\1=${PKG_SYSCONFDIR}|'

SUBST_CLASSES+=                 conf_bin_tail
SUBST_STAGE.conf_bin_tail=      post-extract
SUBST_MESSAGE.conf_bin_tail=    Replacing directories
SUBST_FILES.conf_bin_tail=      logrider.conf logrider.sh
SUBST_SED.conf_bin_tail=        -E -e 's|LOGTAIL(:?)=/usr|LOGTAIL\1=${PREFIX}|'


BUILD_DEFS+=		VARBASE
EGDIR=			${PREFIX}/share/examples/logrider
INSTALLATION_DIRS=	bin ${EGDIR} ${EGDIR}/violations_ignore
OWN_DIRS=		${PKG_SYSCONFDIR}/logrider ${PKG_SYSCONFDIR}/logrider/violations_ignore ${VARBASE}/lib/logrider

CONF_FILES= ${EGDIR}/logrider.conf ${PKG_SYSCONFDIR}/logrider/logrider.conf
CONF_FILES+= ${EGDIR}/hacking ${PKG_SYSCONFDIR}/logrider/hacking
CONF_FILES+= ${EGDIR}/ignore ${PKG_SYSCONFDIR}/logrider/ignore
CONF_FILES+= ${EGDIR}/violations ${PKG_SYSCONFDIR}/logrider/violations
CONF_FILES+= ${EGDIR}/violations_ignore/cvspserver ${PKG_SYSCONFDIR}/logrider/violations_ignore/cvspserver
CONF_FILES+= ${EGDIR}/violations_ignore/ftp ${PKG_SYSCONFDIR}/logrider/violations_ignore/ftp
CONF_FILES+= ${EGDIR}/violations_ignore/misc ${PKG_SYSCONFDIR}/logrider/violations_ignore/misc
CONF_FILES+= ${EGDIR}/violations_ignore/nsfbackup ${PKG_SYSCONFDIR}/logrider/violations_ignore/nsfbackup
CONF_FILES+= ${EGDIR}/violations_ignore/postfix ${PKG_SYSCONFDIR}/logrider/violations_ignore/postfix
CONF_FILES+= ${EGDIR}/violations_ignore/drweb-postfix ${PKG_SYSCONFDIR}/logrider/violations_ignore/drweb-postfix
CONF_FILES+= ${EGDIR}/violations_ignore/microbackup ${PKG_SYSCONFDIR}/logrider/violations_ignore/microbackup
CONF_FILES+= ${EGDIR}/violations_ignore/named ${PKG_SYSCONFDIR}/logrider/violations_ignore/named
CONF_FILES+= ${EGDIR}/violations_ignore/pam ${PKG_SYSCONFDIR}/logrider/violations_ignore/pam
CONF_FILES+= ${EGDIR}/violations_ignore/sshd ${PKG_SYSCONFDIR}/logrider/violations_ignore/sshd

V_IGNORE=		${WRKSRC}/violations_ignore

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/logtail.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/logrider.sh ${DESTDIR}${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/ignore ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/logrider.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/hacking ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/violations ${DESTDIR}${EGDIR}

	cd ${V_IGNORE} && for example in *; do \
			${INSTALL_DATA} "$${example}" ${DESTDIR}${EGDIR}/violations_ignore; \
			done

.include "../../mk/bsd.pkg.mk"
