# $NetBSD: Makefile,v 1.12 2019/08/11 13:21:40 wiz Exp $
#

DISTNAME=		policyd-weight-0.1.14.17
PKGREVISION=		8
CATEGORIES=		mail
MASTER_SITES=		http://www.policyd-weight.org/releases/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.policyd-weight.org/
COMMENT=		Weighted policy daemon for postfix

DEPENDS+=		p5-Net-DNS>=0.58:../../net/p5-Net-DNS

USE_TOOLS+=		perl:run
USE_LANGUAGES=		# none
REPLACE_PERL+=		policyd-weight

BUILD_DEFS+=		VARBASE

POLICYD_WEIGHT_USER?=	polw
POLICYD_WEIGHT_GROUP?=	polw

BUILD_DEFS+=		POLICYD_WEIGHT_GROUP POLICYD_WEIGHT_USER
FILES_SUBST+=		POLICYD_WEIGHT_GROUP=${POLICYD_WEIGHT_GROUP:Q}
FILES_SUBST+=		POLICYD_WEIGHT_USER=${POLICYD_WEIGHT_USER:Q}

PKG_GROUPS=		${POLICYD_WEIGHT_GROUP}
PKG_USERS=		${POLICYD_WEIGHT_USER}:${POLICYD_WEIGHT_GROUP}
PKG_GECOS.${POLICYD_WEIGHT_USER}=	Policyd-weight User

DOCDIR=			${PREFIX}/share/doc/policyd-weight
EGDIR=			${PREFIX}/share/examples/policyd-weight
CONF_FILES=		${EGDIR}/policyd-weight.conf \
			${PKG_SYSCONFDIR}/policyd-weight.conf
RCD_SCRIPTS=		policyd_weight

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	post-build
SUBST_FILES.fix-paths=	policyd-weight policyd-weight.conf.sample
SUBST_SED.fix-paths=	-e 's,"/var/run/,"${VARBASE}/run/,g'
SUBST_SED.fix-paths+=	-e 's,"/etc/policyd-weight.conf","${PKG_SYSCONFDIR}/policyd-weight.conf",g'
SUBST_SED.fix-paths+=	-e 's,"polw";,"${POLICYD_WEIGHT_USER}";,g'

do-build:		replace-interpreter

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/policyd-weight ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/changes.txt ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation.txt ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/policyd-weight.conf.sample \
		${DESTDIR}${EGDIR}/policyd-weight.conf

.include "../../mk/bsd.pkg.mk"
