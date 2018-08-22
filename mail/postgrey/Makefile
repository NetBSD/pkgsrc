# $NetBSD: Makefile,v 1.48 2018/08/22 09:45:33 wiz Exp $

DISTNAME=	postgrey-1.36
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://postgrey.schweikert.ch/pub/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://postgrey.schweikert.ch/
COMMENT=	Postfix Greylist Policy Server
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-BerkeleyDB-[0-9]*:../../databases/p5-BerkeleyDB
DEPENDS+=	p5-IO-Multiplex-[0-9]*:../../devel/p5-IO-Multiplex
DEPENDS+=	p5-Net-Server-[0-9]*:../../net/p5-Net-Server
DEPENDS+=	p5-NetAddr-IP-[0-9]*:../../net/p5-NetAddr-IP

BDB_ACCEPTED=		db4 db5
NO_CONFIGURE=		yes
USE_TOOLS+=		perl:run

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

POSTGREY_USER?=		postgrey
POSTGREY_GROUP?=	postgrey
POSTGREY_DBDIR?=	${VARBASE}/db/${PKGBASE}

PKG_SYSCONFSUBDIR=	postfix

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
FILES_SUBST+=		POSTGREY_USER=${POSTGREY_USER}
FILES_SUBST+=		POSTGREY_GROUP=${POSTGREY_GROUP}
FILES_SUBST+=		POSTGREY_DBDIR=${POSTGREY_DBDIR}

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

INSTALLATION_DIRS+=	sbin ${DOCDIR} ${EGDIR}

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/postgrey ${DESTDIR}${PREFIX}/sbin/postgrey
.for i in COPYING Changes README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/${DOCDIR}/${i}
.endfor
.for i in postgrey_whitelist_clients postgrey_whitelist_recipients
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/${EGDIR}/${i}
.endfor

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
