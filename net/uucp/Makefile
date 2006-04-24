# $NetBSD: Makefile,v 1.1.1.1 2006/04/24 23:21:46 jlam Exp $

DISTNAME=	uucp-1.07
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=uucp/}

MAINTAINER=	pkgsrc-users@pkgsrc.org
COMMENT=	Taylor UUCP
HOMEPAGE=	http://www.airs.com/ian/uucp.html

USE_TOOLS+=	mkdir:run pwd:run rmdir:run

PKG_SYSCONFSUBDIR=	uucp
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-user=uucp
CONFIGURE_ARGS+=	--with-newconfigdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-oldconfigdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		MKDIR_PROGRAM=${TOOLS_MKDIR:Q}
CONFIGURE_ENV+=		PWD_PROGRAM=${TOOLS_PWD_CMD:Q}
CONFIGURE_ENV+=		RMDIR_PROGRAM=${TOOLS_RMDIR:Q}

UUCP_GROUP?=	daemon
PKG_GROUPS=	${UUCP_GROUP}
PKG_USERS=	uucp:${UUCP_GROUP}

INFO_FILES=	# PLIST

# UUCP installs many set-uid "uucp" binaries.
SPECIAL_PERMS+=	bin/cu uucp ${ROOT_GROUP} 4555
SPECIAL_PERMS+=	bin/uucp uucp ${ROOT_GROUP} 4555
SPECIAL_PERMS+=	bin/uuname uucp ${ROOT_GROUP} 4555
SPECIAL_PERMS+=	bin/uustat uucp ${ROOT_GROUP} 4555
SPECIAL_PERMS+=	bin/uux uucp ${ROOT_GROUP} 4555
SPECIAL_PERMS+=	sbin/uucico uucp ${ROOT_GROUP} 4555
SPECIAL_PERMS+=	sbin/uuxqt uucp ${ROOT_GROUP} 4555

.include "../../mk/bsd.pkg.mk"
