# $NetBSD: Makefile,v 1.20 2006/07/10 20:32:59 sketch Exp $
#

DISTNAME=		gld-1.6
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://www.gasmi.net/down/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gasmi.net/
COMMENT=		Standalone greylisting server for Postfix

GNU_CONFIGURE=		yes

LDFLAGS.SunOS+=		-lsocket -lnsl -lresolv

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES_PERMS=	${EGDIR}/gld.conf ${PKG_SYSCONFDIR}/gld.conf	\
			${BINOWN} ${GLD_GROUP} 0640

RCD_SCRIPTS=		gld
GLD_USER?=		gld
GLD_GROUP?=		gld
PKG_GROUPS=             ${GLD_GROUP}
PKG_USERS=              ${GLD_USER}:${GLD_GROUP}
PKG_GECOS.${GLD_USER}=	Greylisting Daemon user
BUILD_DEFS+=		GLD_USER GLD_GROUP

SUBST_CLASSES+=		gld users
SUBST_STAGE.gld=	post-patch
SUBST_FILES.gld=	gld.h
SUBST_SED.gld=		-e "s,/etc,${PKG_SYSCONFDIR},"
SUBST_MESSAGE.gld=	Fixing harcoded paths.
SUBST_STAGE.users=	post-patch
SUBST_FILES.users=	gld.conf
SUBST_SED.users+=	-e "s|^USER=nobody|USER=${GLD_USER}|"
SUBST_SED.users+=	-e "s|^GROUP=nobody|GROUP=${GLD_GROUP}|"
SUBST_MESSAGE.users=	Adjusting user/group in configuration file.

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
