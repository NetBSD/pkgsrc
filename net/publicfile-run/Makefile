# $NetBSD: Makefile,v 1.1 2015/01/27 23:01:31 schmonz Exp $

DISTNAME=		publicfile-run-20150109
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		jlmuir@imca-cat.org
COMMENT=		Configures publicfile to serve public files
LICENSE=		2-clause-bsd

DEPENDS+=		publicfile>=0.52:../../net/publicfile
DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
NO_CHECKSUM=		yes
REPLACE_SH=		libexec-pubftpd

PKG_GROUPS=		pubfile
PKG_USERS+=		pubftp:pubfile
PKG_USERS+=		pubhttp:pubfile
PKG_USERS+=		publog:pubfile
RCD_SCRIPTS=		pubfile pubftpd pubhttpd

MESSAGE_SUBST+=		VARBASE=${VARBASE:Q}

EVAL_PREFIX+=		DAEMONTOOLS_PREFIX=daemontools
EVAL_PREFIX+=		PUBLICFILE_PREFIX=publicfile
EVAL_PREFIX+=		UCSPI_TCP_PREFIX=ucspi-tcp

FILES_SUBST+=		PKGNAME=${PKGNAME:Q}
FILES_SUBST+=		DAEMONTOOLS_PREFIX=${DAEMONTOOLS_PREFIX:Q}
FILES_SUBST+=		PUBLICFILE_PREFIX=${PUBLICFILE_PREFIX:Q}
FILES_SUBST+=		UCSPI_TCP_PREFIX=${UCSPI_TCP_PREFIX:Q}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Substituting paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	libexec-pubftpd
SUBST_VARS.paths=	UCSPI_TCP_PREFIX

BUILD_DEFS+=		VARBASE

INSTALLATION_DIRS=	libexec share/doc/publicfile-run

.include "../../mk/bsd.prefs.mk"

post-extract:
	${CP} ${FILESDIR}/libexec-pubftpd.sh ${WRKSRC}/libexec-pubftpd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libexec-pubftpd \
	    ${DESTDIR}${PREFIX}/libexec/pubftpd
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc \
	    ${DESTDIR}${PREFIX}/share/doc/publicfile-run

.include "../../mk/bsd.pkg.mk"
