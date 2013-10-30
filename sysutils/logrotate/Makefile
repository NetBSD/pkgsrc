# $NetBSD: Makefile,v 1.7 2013/10/30 20:16:25 gls Exp $
#

DISTNAME=		logrotate-3.8.7
CATEGORIES=		sysutils
MASTER_SITES=		https://fedorahosted.org/releases/l/o/logrotate/
FETCH_USING=		curl

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://fedorahosted.org/logrotate/
COMMENT=		Daemon to rotate, compress, remove and mail system log files
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake gzip:run gunzip:run mail:run
NO_EXPORT_CPP=		yes

CFLAGS+=		-DSTATEFILE=\"${VARBASE}/db/logrotate.status\"
CFLAGS+=		-DDEFAULT_MAIL_COMMAND=\"${MAIL_CMD:Q}\"
CFLAGS+=		-DCOMPRESS_COMMAND=\"${GZIP_CMD:[1]:Q}\"
CFLAGS+=		-DUNCOMPRESS_COMMAND=\"${GUNZIP_CMD:[1]:Q}\"

MAKE_ENV+=		RPM_OPT_FLAGS=${CFLAGS:Q}

BUILD_DEFS+=		VARBASE
EGDIR=			${PREFIX}/share/examples/logrotate
CONF_FILES=		${EGDIR}/logrotate.conf ${PKG_SYSCONFDIR}/logrotate.conf
OWN_DIRS=		${PKG_SYSCONFDIR}/logrotate.d
MESSAGE_SUBST+=		EGDIR=${EGDIR}
INSTALLATION_DIRS+=	${EGDIR} ${PKG_SYSCONFDIR} ${OWN_DIRS}
AUTO_MKDIRS=		yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_MESSAGE.paths=	Substituting paths variables.
SUBST_FILES.paths=	examples/logrotate-default
SUBST_FILES.paths+=	examples/logrotate.cron
SUBST_FILES.paths+=	logrotate.8
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	VARBASE
SUBST_VARS.paths+=	PKG_SYSCONFDIR

DOCDIR=			share/doc/logrotate
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/logrotate ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/examples/logrotate-default ${DESTDIR}${EGDIR}/logrotate.conf
	${INSTALL_DATA} ${WRKSRC}/examples/logrotate.cron ${DESTDIR}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/logrotate.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/logrotate.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
