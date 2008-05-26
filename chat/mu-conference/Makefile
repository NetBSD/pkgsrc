# $NetBSD: Makefile,v 1.20 2008/05/26 02:13:16 joerg Exp $
#

DISTNAME=		mu-conference-0.6.0
PKGREVISION=		6
CATEGORIES=		chat
MASTER_SITES=		http://jabber.terrapin.com/JCR/ http://www.jabberstudio.org/projects/mu-conference/releases/download.php?file=
DISTFILES=		${DISTNAME}.tar.gz jcr-0.1.2.tar.gz

MAINTAINER=		abs@mono.org
HOMEPAGE=		http://jabber.terrapin.com/JCR/
COMMENT=		Implementation of the JEP-0045 Multi-User Chat protocol

DEPENDS+=		jabberd-[0-9]*:../../chat/jabberd2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/jcr-0.1.2
SUBWRKSRC=		${WRKSRC}/${DISTNAME}/src
XMLCONFIG=		${WRKDIR}/${DISTNAME}/muc-jcr.xml

USE_TOOLS+=		gmake pax pkg-config

PKG_SYSCONFSUBDIR=	jabberd
RCD_SCRIPTS=		muc

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		JABBERD_LOGDIR JABBERD_PIDDIR
JABBERD_USER?=		jabberd
PKG_USERS_VARS+=	JABBERD_USER

FILES_SUBST+=		JABBERD_PIDDIR=${JABBERD_PIDDIR:Q}
FILES_SUBST+=		JABBERD_USER=${JABBERD_USER:Q}

EGDIR=			${PREFIX}/share/examples/jabberd
CONF_FILES+=		${EGDIR}/muc-jcr.xml ${PKG_SYSCONFDIR:Q}/muc-jcr.xml

INSTALLATION_DIRS=	bin share/examples/jabberd

post-extract:
	@${MV} ${XMLCONFIG:Q} ${XMLCONFIG:Q}.in

pre-configure:
	@${SED}	-e 's|\(<logdir>\)[^<]*|\1${JABBERD_LOGDIR}|g' \
		-e 's|\(<pidfile>\).|\1${JABBERD_PIDDIR}|g' \
		-e 's|\(<spool>\).|\1${JABBERD_SPOOLDIR}|g' \
		${XMLCONFIG:Q}.in > ${XMLCONFIG:Q}

pre-build:
	cd ${WRKDIR:Q} && pax -rw -pe ${DISTNAME:Q} ${WRKSRC:Q}

post-build:
	${CP} ${WRKSRC:Q}/src/main.c ${WRKSRC:Q}/src/jcomp.mk ${SUBWRKSRC:Q}
	cd ${SUBWRKSRC:Q} && ${SETENV} ${MAKE_ENV} ${GMAKE} -f jcomp.mk

do-install:
	${INSTALL_PROGRAM} ${SUBWRKSRC:Q}/mu-conference ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC:Q}/${DISTNAME:Q}/muc-jcr.xml ${DESTDIR}${EGDIR}

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
