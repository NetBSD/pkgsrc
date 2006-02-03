# $NetBSD: Makefile,v 1.14 2006/02/03 02:24:07 rillig Exp $
#

DISTNAME=		mu-conference-0.6.0
PKGREVISION=		4
CATEGORIES=		chat
MASTER_SITES=		http://jabber.terrapin.com/JCR/ http://www.jabberstudio.org/projects/mu-conference/releases/download.php?file=
DISTFILES=		${DISTNAME}.tar.gz jcr-0.1.2.tar.gz

MAINTAINER=		abs@mono.org
HOMEPAGE=		http://jabber.terrapin.com/JCR/
COMMENT=		Implementation of the JEP-0045 Multi-User Chat protocol

DEPENDS+=		jabberd-[0-9]*:../../chat/jabberd2

WRKSRC=			${WRKDIR}/jcr-0.1.2
SUBWRKSRC=		${WRKSRC}/${DISTNAME}/src
XMLCONFIG=		${WRKDIR}/${DISTNAME}/muc-jcr.xml

USE_TOOLS+=		gmake pkg-config

PKG_SYSCONFSUBDIR=	jabberd
RCD_SCRIPTS=		muc

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		JABBERD_USER JABBERD_LOGDIR JABBERD_PIDDIR
JABBERD_USER?=		jabberd

FILES_SUBST+=		JABBERD_PIDDIR=${JABBERD_PIDDIR:Q}
FILES_SUBST+=		JABBERD_USER=${JABBERD_USER:Q}

EGDIR=			${PREFIX}/share/examples/jabberd
CONF_FILES+=		${EGDIR:Q}/muc-jcr.xml ${PKG_SYSCONFDIR:Q}/muc-jcr.xml

INSTALLATION_DIRS=	bin

post-extract:
	@${MV} ${XMLCONFIG:Q} ${XMLCONFIG:Q}.in

pre-configure:
	@${SED}	-e 's|\(<logdir>\)[^<]*|\1${JABBERD_LOGDIR}|g' \
		-e 's|\(<pidfile>\).|\1${JABBERD_PIDDIR}|g' \
		-e 's|\(<spool>\).|\1${JABBERD_SPOOLDIR}|g' \
		${XMLCONFIG:Q}.in > ${XMLCONFIG:Q}

pre-build:
	cd ${WRKDIR:Q} && ${PAX} -rw -pe ${DISTNAME:Q} ${WRKSRC:Q}

post-build:
	${CP} ${WRKSRC:Q}/src/main.c ${WRKSRC:Q}/src/jcomp.mk ${SUBWRKSRC:Q}
	cd ${SUBWRKSRC:Q} && ${SETENV} ${MAKE_ENV} ${GMAKE} -f jcomp.mk

do-install:
	${INSTALL_PROGRAM} ${SUBWRKSRC:Q}/mu-conference ${PREFIX:Q}/bin
	${INSTALL_DATA} ${WRKSRC:Q}/${DISTNAME:Q}/muc-jcr.xml ${EGDIR:Q}

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
