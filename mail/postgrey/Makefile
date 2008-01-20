# $NetBSD: Makefile,v 1.23 2008/01/20 21:08:01 xtraeme Exp $
#

DISTNAME=	postgrey-1.31
#PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://postgrey.schweikert.ch/pub/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://postgrey.schweikert.ch/
COMMENT=	Postfix Greylist Policy Server

DEPENDS+=	p5-BerkeleyDB-[0-9]*:../../databases/p5-BerkeleyDB
DEPENDS+=	p5-IO-Multiplex-[0-9]*:../../devel/p5-IO-Multiplex
DEPENDS+=	p5-Net-Server-[0-9]*:../../net/p5-Net-Server

NO_CONFIGURE=	yes
USE_TOOLS+=	perl:run

.include "../../mk/bsd.prefs.mk"

POSTGREY_USER?=		postgrey
POSTGREY_GROUP?=	postgrey
POSTGREY_DBDIR?=	${VARBASE}/db/${PKGBASE}

PKG_SYSCONFSUBDIR?=	postfix

DOCDIR=			share/doc/${PKGBASE}
EGDIR=			share/examples/${PKGBASE}

RCD_SCRIPTS=		postgrey
PKG_GROUPS=		${POSTGREY_GROUP}
PKG_USERS=		${POSTGREY_USER}:${POSTGREY_GROUP}
PKG_GROUPS_VARS+=	POSTGREY_GROUP
PKG_USERS_VARS+=	POSTGREY_USER

PKG_GECOS.${POSTGREY_USER}=	Postgrey Daemon User

BUILD_DEFS+=		POSTGREY_DBDIR VARBASE

.for i in postgrey_whitelist_clients postgrey_whitelist_recipients
CONF_FILES+=		${PREFIX}/${EGDIR}/${i} \
			${PKG_SYSCONFDIR}/${i}
.endfor

OWN_DIRS_PERMS+=	${POSTGREY_DBDIR} \
			${POSTGREY_USER} ${POSTGREY_GROUP} 0775

FILES_SUBST+=		PERL=${PERL5:Q}

SUBST_CLASSES+=		postgrey
SUBST_STAGE.postgrey=	pre-build
SUBST_FILES.postgrey=	postgrey
# Perl
SUBST_SED.postgrey=	-e 's,/usr/bin/perl,${PERL5},g'
# User
SUBST_SED.postgrey+=	-e "s,|| 'postgrey',|| '${POSTGREY_USER}',g"
SUBST_SED.postgrey+=	-e "s,default: postgrey,default: ${POSTGREY_USER},g"
SUBST_SED.postgrey+=	-e "s,C<postgrey>,C<${POSTGREY_USER}>,g"
# Group
SUBST_SED.postgrey+=	-e "s,|| 'nogroup',|| '${POSTGREY_GROUP}',g"
SUBST_SED.postgrey+=	-e "s,default: nogroup,default: ${POSTGREY_GROUP},g"
# Database
SUBST_SED.postgrey+=	-e 's,/var/spool/postfix/postgrey,${POSTGREY_DBDIR},g'
# Config
SUBST_SED.postgrey+=	-e 's,/etc/postfix,${PKG_SYSCONFDIR},g'
#
SUBST_MESSAGE.postgrey=	Fixing defaults.

INSTALLATION_DIRS=	sbin ${DOCDIR} ${EGDIR}

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/postgrey ${PREFIX}/sbin/postgrey
.for i in COPYING Changes README
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}/${i}
.endfor
.for i in postgrey_whitelist_clients postgrey_whitelist_recipients
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${EGDIR}/${i}
.endfor

.include "../../databases/db4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
