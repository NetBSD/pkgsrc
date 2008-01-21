# $NetBSD: Makefile,v 1.12 2008/01/21 13:52:17 obache Exp $

DISTNAME=	uucp-1.07
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=uucp/}

MAINTAINER=	pkgsrc-users@pkgsrc.org
COMMENT=	Taylor UUCP
HOMEPAGE=	http://www.airs.com/ian/uucp.html

USE_TOOLS+=	mkdir:run pwd:run rmdir:run

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	uucp
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-user=${UUCP_USER}
CONFIGURE_ARGS+=	--with-newconfigdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-oldconfigdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		MKDIR_PROGRAM=${TOOLS_MKDIR:Q}
CONFIGURE_ENV+=		PWD_PROGRAM=${TOOLS_PWD_CMD:Q}
CONFIGURE_ENV+=		RMDIR_PROGRAM=${TOOLS_RMDIR:Q}

PKG_GROUPS=	${UUCP_GROUP}
PKG_USERS=	${UUCP_USER}:${UUCP_GROUP}

PKG_GROUPS_VARS+=	UUCP_GROUP
PKG_USERS_VARS+=	UUCP_USER

PKG_GECOS.${UUCP_USER}=	UNIX-to-UNIX Copy
PKG_HOMES.${UUCP_USER}=	${UUCP_PUBDIR}
PKG_SHELL.${UUCP_USER}=	${PREFIX}/sbin/uucico

INFO_FILES=	# PLIST

# UUCP installs many set-uid "uucp" binaries.
SPECIAL_PERMS+=	bin/cu ${UUCP_USER} ${BINGRP} 4555
SPECIAL_PERMS+=	bin/uucp ${UUCP_USER} ${BINGRP} 4555
SPECIAL_PERMS+=	bin/uuname ${UUCP_USER} ${BINGRP} 4555
SPECIAL_PERMS+=	bin/uustat ${UUCP_USER} ${BINGRP} 4555
SPECIAL_PERMS+=	bin/uux ${UUCP_USER} ${BINGRP} 4555
SPECIAL_PERMS+=	sbin/uucico ${UUCP_USER} ${BINGRP} 4555
SPECIAL_PERMS+=	sbin/uuxqt ${UUCP_USER} ${BINGRP} 4555

SENDMAIL?=	/usr/sbin/sendmail

UUCP_MAIL_PROGRAM?=	${SENDMAIL} -t
UUCP_CMDPATH?=		/bin /usr/bin ${PREFIX}/bin
UUCP_LOCKDIR?=		${VARBASE}/spool/lock
UUCP_SPOOLDIR?=		${VARBASE}/spool/uucp
UUCP_PUBDIR?=		${UUCP_SPOOLDIR}public
UUCP_LOGFILE?=		${UUCP_SPOOLDIR}/Log
UUCP_STATFILE?=		${UUCP_SPOOLDIR}/Stats
UUCP_DEBUGFILE?=	${UUCP_SPOOLDIR}/Debug

OWN_DIRS_PERMS=		${UUCP_LOCKDIR} ${UUCP_USER} ${UUCP_GROUP} 0755
OWN_DIRS_PERMS+=	${UUCP_SPOOLDIR} ${UUCP_USER} ${UUCP_GROUP} 0755
OWN_DIRS_PERMS+=	${UUCP_PUBDIR} ${UUCP_USER} ${UUCP_GROUP} 1777

SUBST_CLASSES+=		nbsd
SUBST_STAGE.nbsd=	post-configure
SUBST_MESSAGE.nbsd=	Fixing Makefiles for rmail and uucpd.
SUBST_FILES.nbsd=	rmail/Makefile uucpd/Makefile
SUBST_FILES.nbsd+=	uucpd/pathnames.h uucpd/uucpd.8
SUBST_VARS.nbsd=	PREFIX PKGMANDIR UUCPD_CPPFLAGS UUCPD_LIBS	\
			INSTALL_PROGRAM INSTALL_MAN

# The necessary libraries and compiler flags for building uucpd are
# platform-specific.
#
UUCPD_CPPFLAGS.${OPSYS}=	# empty
.if exists(/usr/include/utmp.h)
UUCPD_CPPFLAGS.${OPSYS}+=	-DSUPPORT_UTMP
.endif
.if exists(/usr/include/utmpx.h)
UUCPD_CPPFLAGS.${OPSYS}+=	-DSUPPORT_UTMPX
.endif
UUCPD_CPPFLAGS.Darwin=	-DSUPPORT_UTMP
UUCPD_CPPFLAGS.*=	# empty
UUCPD_LIBS.Darwin=	# empty
UUCPD_LIBS.*=		-lcrypt -lutil
OPSYSVARS+=		UUCPD_CPPFLAGS UUCPD_LIBS

INSTALLATION_DIRS=	bin libexec ${PKGMANDIR}/man8 share/examples/uucp

post-extract:
	${CP} -R ${FILESDIR}/rmail ${WRKSRC}
	${CP} -R ${FILESDIR}/uucpd ${WRKSRC}

# Generate a policy_local.h header file that holds the paths used by UUCP.
post-configure:
	@${RM} -f ${WRKSRC}/policy_local.h
.for _var_ in	MAIL_PROGRAM	CMDPATH		LOCKDIR			\
		SPOOLDIR	PUBDIR		LOGFILE			\
		STATFILE	DEBUGFILE
	@${ECHO} "#define ${_var_}	\""${UUCP_${_var_}:Q}"\""	\
		>> ${WRKSRC}/policy_local.h
.endfor

post-install:
	cd ${FILESDIR}/etc; for f in [a-z]*; do				\
		${TEST} -f $$f || continue;				\
		${INSTALL_DATA} $$f ${PREFIX}/share/examples/uucp;	\
	done

.include "../../mk/bsd.pkg.mk"
