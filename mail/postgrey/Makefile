# $NetBSD: Makefile,v 1.7 2005/06/16 06:58:08 jlam Exp $
#

DISTNAME=	postgrey-1.21
PKGREVISION=	# empty
CATEGORIES=	mail
MASTER_SITES=	http://isg.ee.ethz.ch/tools/postgrey/pub/ \
		http://isg.ee.ethz.ch/tools/postgrey/pub/old/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://isg.ee.ethz.ch/tools/postgrey/
COMMENT=	Postfix Greylist Policy Server

DEPENDS+=	p5-BerkeleyDB-[0-9]*:../../databases/p5-BerkeleyDB
DEPENDS+=	p5-IO-Multiplex-[0-9]*:../../devel/p5-IO-Multiplex
DEPENDS+=	p5-Net-Server-[0-9]*:../../net/p5-Net-Server

NO_CONFIGURE=	yes
USE_PKGINSTALL=	yes
USE_PERL5=	yes

.include "../../mk/bsd.prefs.mk"

POSTGREY_USER?=		postgrey
POSTGREY_GROUP?=	postgrey
POSTGREY_DBDIR?=	${VARBASE}/db/${PKGBASE}

PKG_SYSCONFSUBDIR?=	postfix

DOCDIR=			share/doc/${PKGBASE}
EGDIR=			share/examples/${PKGBASE}

RCD_SCRIPTS=		postgrey
PKG_GROUPS=		${POSTGREY_GROUP}
PKG_USERS=		${POSTGREY_USER}:${POSTGREY_GROUP}::Postgrey\\ Daemon

.for i in postgrey_whitelist_clients postgrey_whitelist_recipients
CONF_FILES+=		${PREFIX}/${EGDIR}/${i} \
			${PKG_SYSCONFDIR}/${i}
.endfor

OWN_DIRS+=		${PREFIX}/${DOCDIR}
OWN_DIRS+=		${PREFIX}/${EGDIR}

OWN_DIRS_PERMS+=	${POSTGREY_DBDIR} \
			${POSTGREY_USER} ${POSTGREY_GROUP} 0775

FILES_SUBST+=		PERL="${PERL5}"

PLIST_SUBST+=		DOCDIR="${DOCDIR}"
PLIST_SUBST+=		EGDIR="${EGDIR}"

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
SUBST_MESSAGE.postgrey=	"Fixing defaults"

INSTALLATION_DIRS=	sbin

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
