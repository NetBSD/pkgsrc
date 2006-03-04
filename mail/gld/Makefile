# $NetBSD: Makefile,v 1.16 2006/03/04 21:30:00 jlam Exp $
#

DISTNAME=		gld-1.6
CATEGORIES=		mail
MASTER_SITES=		http://www.gasmi.net/down/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gasmi.net/
COMMENT=		Standalone greylisting server for Postfix

GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES_PERMS=	${EGDIR}/gld.conf ${PKG_SYSCONFDIR}/gld.conf	\
			${BINOWN} ${GLD_GROUP} 0740

RCD_SCRIPTS=		gld
GLD_USER?=		gld
GLD_GROUP?=		gld
PKG_GROUPS=             ${GLD_GROUP}
PKG_USERS=              ${GLD_USER}:${GLD_GROUP}::Greylisting\ Daemon\ user

SUBST_CLASSES+=		gld users
SUBST_STAGE.gld=	post-patch
SUBST_FILES.gld=	gld.h
SUBST_SED.gld=		-e "s,/etc,${PKG_SYSCONFDIR},"
SUBST_MESSAGE.gld=	Fixing harcoded paths.
SUBST_STAGE.users=	post-patch
SUBST_FILES.users=	gld.conf
SUBST_SED.users+=	-e "s|\#USER=nobody|USER=${GLD_USER}|"
SUBST_SED.users+=	-e "s|\#GROUP=nobody|GROUP=${GLD_GROUP}|"
SUBST_MESSAGE.users=	Adjusting user/group in configuration file.

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
