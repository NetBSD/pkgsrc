# $NetBSD: Makefile,v 1.79 2006/09/16 07:09:22 schwarz Exp $

DISTNAME=	exim-4.63
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/exim4/ \
		ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim4/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/exim4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

CONFLICTS+=	exim-exiscan-[0-9]*

USE_TOOLS+=	perl:run
INSTALLATION_DIRS+=	${PKGMANDIR}/man8

MAKE_ENV+=	SSLBASE=${SSLBASE:Q}
MAKE_ENV+=	INST_CHOWN=${CHOWN:Q}
MAKE_FLAGS+=	FULLECHO=''

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	EXIM_USER EXIM_GROUP EXIM_DB

PKG_GROUPS=	${EXIM_GROUP}
PKG_USERS=	${EXIM_USER}:${EXIM_GROUP}

PKG_GECOS.${EXIM_USER}=	Exim mail server user
PKG_HOME.${EXIM_USER}=	${VARBASE}/mail
PKG_SHELL.${EXIM_USER}=	${NOLOGIN}

PKG_SYSCONFSUBDIR?=	exim
EXAMPLESDIR=		${PREFIX}/share/examples/exim
CONF_FILES=		${EXAMPLESDIR}/aliases ${PKG_SYSCONFDIR}/aliases
CONF_FILES+=		${EXAMPLESDIR}/configure ${PKG_SYSCONFDIR}/configure
MESSAGE_SUBST+=		EXAMPLESDIR="${EXAMPLESDIR}"
PLIST_SUBST+=		DISTNAME=${DISTNAME:Q}

RCD_SCRIPTS=		exim

OWN_DIRS_PERMS=		${VARBASE}/log/exim ${EXIM_USER} ${EXIM_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/spool/exim ${EXIM_USER} ${EXIM_GROUP} 0750

# XXX: The following will be handled by buildlink3 at some point.
CFLAGS+=		${_STRIPFLAG_CC}

# pay attention to CPPFLAGS as well
CFLAGS+=		${CPPFLAGS}

.include "options.mk"

# BDB_TYPE gets set to "db1" if USE_DB185=="yes"
USE_DB185?=		no
BDB_ACCEPTED?=		db1 db2 db3 db4

post-extract:
	${MKDIR} ${WRKSRC}/Local
	${CP} ${WRKSRC}/src/EDITME ${WRKSRC}/Local/Makefile.pkgsrc
	${CP} ${WRKSRC}/exim_monitor/EDITME ${WRKSRC}/Local/eximon.conf.pkgsrc
	${CP} ${FILESDIR}/Makefile-DragonFly ${FILESDIR}/os.h-DragonFly \
		${WRKSRC}/OS/

pre-configure:
	@${SED} -e 's:@PREFIX@:${PREFIX}:' \
		-e 's:@PKG_SYSCONFDIR@:${PKG_SYSCONFDIR}:' \
		-e 's:@EXIM_USER@:${EXIM_USER}:' \
		-e 's:@EXIM_GROUP@:${EXIM_GROUP}:' \
		-e 's:@EXIM_USE_DB_CONFIG@:${EXIM_USE_DB_CONFIG}:' \
		-e 's:@EXIM_DBMLIB@:${EXIM_DBMLIB}:' \
		-e 's:@EXIM_INCLUDE@:${EXIM_INCLUDE}:' \
		-e 's:@LOOKUP_LIBS@:${LOOKUP_LIBS}:' \
		-e 's:@CHOWN@:${CHOWN}:' \
		-e 's:@CHGRP@:${CHGRP}:' \
		-e 's:@MV@:${MV}:' \
		-e 's:@RM@:${RM}:' \
		-e 's:@PERL5@:${PERL5}:' \
		-e 's:@VARBASE@:${VARBASE}:' \
	    < ${WRKSRC}/Local/Makefile.pkgsrc \
	    > ${WRKSRC}/Local/Makefile
.for opt in ${LOCAL_MAKEFILE_OPTIONS}
	@${ECHO} ${opt} >> ${WRKSRC}/Local/Makefile
.endfor
	@${SED} -e 's:@PREFIX@:${PREFIX}:' \
		-e 's:@PKG_SYSCONFDIR@:${PKG_SYSCONFDIR}:' \
	    < ${WRKSRC}/Local/eximon.conf.pkgsrc \
	    > ${WRKSRC}/Local/eximon.conf
# CFLAGS is already set by pkgsrc
	@for f in ${WRKSRC}/OS/Makefile-*; do \
		${SED} -e 's/^CFLAGS=.*//' $$f > $$f.subst; \
		${MV} -f $$f.subst $$f; \
	done

post-build:
	@${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    ${FILESDIR}/mailer.conf.exim \
	    > ${WRKDIR}/mailer.conf

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/exim.8 ${PREFIX}/${PKGMANDIR}/man8/exim.8

.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
