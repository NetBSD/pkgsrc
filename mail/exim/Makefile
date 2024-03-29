# $NetBSD: Makefile,v 1.202 2023/12/29 17:06:24 bsiegert Exp $

DISTNAME=	exim-4.97.1
CATEGORIES=	mail net
MASTER_SITES=	https://ftp.exim.org/pub/exim/exim4/
MASTER_SITES+=	https://ftp.exim.org/pub/exim/exim4/fixes/
MASTER_SITES+=	ftp://ftp.exim.org/pub/exim/exim4/
MASTER_SITES+=	ftp://ftp.exim.org/pub/exim/exim4/fixes/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail
LICENSE=	gnu-gpl-v2

CONFLICTS+=	exim-exiscan-[0-9]*

DEPENDS+=	p5-File-FcntlLock>=0.22:../../sysutils/p5-File-FcntlLock

USE_TOOLS+=	perl:run
USE_LANGUAGES=	c99

BUILD_DEFS+=	VARBASE

MAKE_ENV+=	SSLBASE=${SSLBASE:Q}
MAKE_ENV+=	INST_CHOWN=${CHOWN:Q}
MAKE_FLAGS+=	FULLECHO=''
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	EXIM_DB EXIM_MAX_INCLUDE_SIZE

PKG_GROUPS=	${EXIM_GROUP}
PKG_USERS=	${EXIM_USER}:${EXIM_GROUP}

PKG_GROUPS_VARS+=	EXIM_GROUP
PKG_USERS_VARS+=	EXIM_USER

PKG_GECOS.${EXIM_USER}=	Exim mail server user
PKG_HOME.${EXIM_USER}=	${VARBASE}/mail
PKG_SHELL.${EXIM_USER}=	${NOLOGIN}

FILES_SUBST+=		EXIM_GROUP=${EXIM_GROUP}
FILES_SUBST+=		EXIM_USER=${EXIM_USER}

PKG_SYSCONFSUBDIR=	exim
EXAMPLESDIR=		${PREFIX}/share/examples/exim
CONF_FILES=		${EXAMPLESDIR}/aliases ${PKG_SYSCONFDIR}/aliases
CONF_FILES+=		${EXAMPLESDIR}/configure ${PKG_SYSCONFDIR}/configure
MESSAGE_SUBST+=		EXAMPLESDIR="${EXAMPLESDIR}"
PLIST_SUBST+=		DISTNAME=${DISTNAME}

RCD_SCRIPTS=		exim

OWN_DIRS_PERMS=		${VARBASE}/log/exim ${EXIM_USER} ${EXIM_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/spool/exim ${EXIM_USER} ${EXIM_GROUP} 0750
SPECIAL_PERMS+=		sbin/${PKGSRC_EXIM_VERSION} ${SETUID_ROOT_PERMS}

# pay attention to CPPFLAGS as well
CFLAGS+=		${CPPFLAGS}
LDFLAGS.NetBSD+=	-lexecinfo

PKGSRC_EXIM_VERSION=	${DISTNAME}-1
SUBST_CLASSES+=		exim
SUBST_STAGE.exim=	pre-configure
SUBST_MESSAGE.exim=	Faking exim version information in exim_install
SUBST_FILES.exim=	scripts/exim_install
SUBST_VARS.exim=	PKGSRC_EXIM_VERSION

SUBST_CLASSES+=		cflags
SUBST_STAGE.cflags=	pre-configure
SUBST_MESSAGE.cflags=	Fixing hard-coded CFLAGS
SUBST_FILES.cflags=	OS/Makefile-*
SUBST_SED.cflags=	-e '/^CFLAGS=/d'
SUBST_SED.cflags+=	-e 's/-D_XOPEN_SOURCE /-D_XOPEN_SOURCE=600 /'
SUBST_SED.cflags+=	-e 's/-D_XOPEN_SOURCE_EXTENDED=1 //'

INSTALL_ARG=		INSTALL_ARG=-no_chown
INSTALL_ENV+=		${INSTALL_ARG:Q}

.include "options.mk"

post-extract:
	mv ${WRKSRC}/OS/unsupported/*-* ${WRKSRC}/OS/
	mkdir ${WRKSRC}/Local
	cp ${WRKSRC}/src/EDITME ${WRKSRC}/Local/Makefile.pkgsrc
	cp ${WRKSRC}/exim_monitor/EDITME ${WRKSRC}/Local/eximon.conf.pkgsrc

pre-configure:
	${SED}	-e 's:@PREFIX@:${PREFIX}:' \
		-e 's:@PKG_SYSCONFDIR@:${PKG_SYSCONFDIR}:' \
		-e 's:@EXIM_USER@:${EXIM_USER}:' \
		-e 's:@EXIM_GROUP@:${EXIM_GROUP}:' \
		-e 's:@EXIM_USE_DB_CONFIG@:${EXIM_USE_DB_CONFIG}:' \
		-e 's:@EXIM_DBMLIB@:${EXIM_DBMLIB}:' \
		-e 's:@EXIM_INCLUDE@:${EXIM_INCLUDE}:' \
		-e 's:@LOOKUP_LIBS@:${LOOKUP_LIBS}:' \
		-e 's:@CHOWN@:${CHOWN}:' \
		-e 's:@CHGRP@:${CHGRP}:' \
		-e 's:@CHMOD@:${CHMOD}:' \
		-e 's:@MV@:${MV}:' \
		-e 's:@RM@:${RM}:' \
		-e 's:@TOUCH@:${TOUCH}:' \
		-e 's:@PERL5@:${PERL5}:' \
		-e 's:@VARBASE@:${VARBASE}:' \
	    < ${WRKSRC}/Local/Makefile.pkgsrc \
	    > ${WRKSRC}/Local/Makefile
.for opt in ${LOCAL_MAKEFILE_OPTIONS}
	${ECHO} ${opt} >> ${WRKSRC}/Local/Makefile
.endfor
.if !empty(EXIM_MAX_INCLUDE_SIZE)
	${ECHO} MAX_INCLUDE_SIZE=${EXIM_MAX_INCLUDE_SIZE} >> ${WRKSRC}/Local/Makefile
.endif
	${SED}	-e 's:@PREFIX@:${PREFIX}:' \
		-e 's:@PKG_SYSCONFDIR@:${PKG_SYSCONFDIR}:' \
	    < ${WRKSRC}/Local/eximon.conf.pkgsrc \
	    > ${WRKSRC}/Local/eximon.conf

post-build:
	${SED}	-e 's:@PREFIX@:${PREFIX}:' \
	    ${FILESDIR}/mailer.conf.exim \
	    > ${WRKDIR}/mailer.conf

INSTALLATION_DIRS+=	${PKGMANDIR}/man8 sbin share/examples/exim share/doc/exim

post-install:
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${DESTDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/exim.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/exim.8
	${INSTALL_DATA} ${WRKSRC}/doc/spec.txt \
		${DESTDIR}${PREFIX}/share/doc/exim

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
