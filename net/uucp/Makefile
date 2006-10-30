# $NetBSD: Makefile,v 1.2 2006/10/30 03:33:59 jlam Exp $

DISTNAME=	uucp-1.07
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=uucp/}

MAINTAINER=	pkgsrc-users@pkgsrc.org
COMMENT=	Taylor UUCP
HOMEPAGE=	http://www.airs.com/ian/uucp.html

USE_TOOLS+=	mkdir:run pwd:run rmdir:run

PKG_SYSCONFSUBDIR=	uucp
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-user=${UUCP_USER}
CONFIGURE_ARGS+=	--with-newconfigdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-oldconfigdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		MKDIR_PROGRAM=${TOOLS_MKDIR:Q}
CONFIGURE_ENV+=		PWD_PROGRAM=${TOOLS_PWD_CMD:Q}
CONFIGURE_ENV+=		RMDIR_PROGRAM=${TOOLS_RMDIR:Q}

UUCP_GROUP?=	daemon
UUCP_USER?=	uucp
PKG_GROUPS=	${UUCP_GROUP}
PKG_USERS=	${UUCP_USER}:${UUCP_GROUP}

INFO_FILES=	# PLIST

# UUCP installs many set-uid "uucp" binaries.
SPECIAL_PERMS+=	bin/cu ${UUCP_USER} ${ROOT_GROUP} 4555
SPECIAL_PERMS+=	bin/uucp ${UUCP_USER} ${ROOT_GROUP} 4555
SPECIAL_PERMS+=	bin/uuname ${UUCP_USER} ${ROOT_GROUP} 4555
SPECIAL_PERMS+=	bin/uustat ${UUCP_USER} ${ROOT_GROUP} 4555
SPECIAL_PERMS+=	bin/uux ${UUCP_USER} ${ROOT_GROUP} 4555
SPECIAL_PERMS+=	sbin/uucico ${UUCP_USER} ${ROOT_GROUP} 4555
SPECIAL_PERMS+=	sbin/uuxqt ${UUCP_USER} ${ROOT_GROUP} 4555

SENDMAIL?=	/usr/sbin/sendmail

UUCP_MAIL_PROGRAM?=	${SENDMAIL} -t
UUCP_CMDPATH?=		/bin /usr/bin ${PREFIX}/bin
UUCP_LOCKDIR?=		${VARBASE}/spool/lock
UUCP_SPOOLDIR?=		${VARBASE}/spool/uucp
UUCP_PUBDIR?=		${UUCP_SPOOLDIR}public
UUCP_LOGFILE?=		${UUCP_SPOOLDIR}/Log
UUCP_STATFILE?=		${UUCP_SPOOLDIR}/Stats
UUCP_DEBUGFILE?=	${UUCP_SPOOLDIR}/Debug

# Generate a policy_local.h header file that holds the paths used by UUCP.
post-configure:
	@${RM} -f ${WRKSRC}/policy_local.h
.for _var_ in	MAIL_PROGRAM	CMDPATH		LOCKDIR			\
		SPOOLDIR	PUBDIR		LOGFILE			\
		STATFILE	DEBUGFILE
	@${ECHO} "#define ${_var_}	\""${UUCP_${_var_}:Q}"\""	\
		>> ${WRKSRC}/policy_local.h
.endfor

.include "../../mk/bsd.pkg.mk"
