# $NetBSD: Makefile,v 1.1.1.1 2004/11/25 05:42:40 xtraeme Exp $
#

DISTNAME=		gld-1.4
CATEGORIES=		mail
MASTER_SITES=		http://www.gasmi.net/down/
EXTRACT_SUFX=		.tgz

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gasmi.net/
COMMENT=		Standalone greylisting server for Postfix

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/gld.conf ${PKG_SYSCONFDIR}/gld.conf

RCD_SCRIPTS=		gld
GLD_USER?=		gld
GLD_GROUP?=		gld
PKG_GROUPS=             ${GLD_GROUP}
PKG_USERS=              ${GLD_USER}:${GLD_GROUP}::Greylisting\\ Daemon\\ user

SUBST_CLASSES+=		gld users
SUBST_STAGE.gld=	post-patch
SUBST_FILES.gld=	gld.h
SUBST_SED.gld=		-e "s,/etc,${PKG_SYSCONFDIR},"
SUBST_MESSAGE.gld=	"Fixing harcoded paths."
SUBST_STAGE.users=	post-patch
SUBST_FILES.users=	gld.conf
SUBST_SED.users+=	-e "s|\#USER=nobody|USER=${GLD_USER}|"
SUBST_SED.users+=	-e "s|\#GROUP=nobody|GROUP=${GLD_GROUP}|"
SUBST_MESSAGE.users=	"Adjusting user/group in configuration file."

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
