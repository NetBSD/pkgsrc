# $NetBSD: Makefile,v 1.16 2017/03/06 12:59:53 fhajny Exp $

DISTNAME=		logrotate-3.11.0
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=logrotate/}

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		https://github.com/logrotate/logrotate/
COMMENT=		Daemon to rotate, compress, remove and mail system log files
LICENSE=		gnu-gpl-v2

GITHUB_RELEASE=		${PKGVERSION_NOREV}

USE_TOOLS+=		gmake gzip:run gunzip:run mail:run
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
NO_EXPORT_CPP=		yes

CONFIGURE_ENV+=		STATEFILE=\"${VARBASE}/db/logrotate.status\"
CONFIGURE_ENV+=		DEFAULT_MAIL_COMMAND=\"${MAIL_CMD:Q}\"
CONFIGURE_ENV+=		COMPRESS_COMMAND=\"${GZIP_CMD:[1]:Q}\"
CONFIGURE_ENV+=		UNCOMPRESS_COMMAND=\"${GUNZIP_CMD:[1]:Q}\"
CONFIGURE_ARGS+=	--with-state-file-path="${VARBASE}/db/logrotate.status"

BUILD_DEFS+=		VARBASE

MESSAGE_SUBST+=		EGDIR=${EGDIR}
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_MESSAGE.paths=	Substituting paths variables.
SUBST_FILES.paths=	examples/logrotate-default
SUBST_FILES.paths+=	examples/logrotate.cron
SUBST_VARS.paths=	PREFIX PKG_SYSCONFDIR

CONF_FILES=		${EGDIR}/logrotate.conf ${PKG_SYSCONFDIR}/logrotate.conf
OWN_DIRS=		${PKG_SYSCONFDIR}/logrotate.d

EGDIR=			share/examples/logrotate

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/logrotate-default \
		${DESTDIR}${PREFIX}/${EGDIR}/logrotate.conf
	${INSTALL_DATA} ${WRKSRC}/examples/logrotate.cron \
		${DESTDIR}${PREFIX}/${EGDIR}

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
