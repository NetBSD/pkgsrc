# $NetBSD: Makefile,v 1.9 2005/06/16 06:57:42 jlam Exp $
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

USE_TOOLS+=		gmake
USE_PKGINSTALL=		yes

PKG_SYSCONFSUBDIR=      jabberd
RCD_SCRIPTS=            muc

BUILD_DEFS+=		JABBERD_USER JABBERD_LOGDIR JABBERD_PIDDIR
JABBERD_USER?=		jabberd

FILES_SUBST+=		JABBERD_PIDDIR=${JABBERD_PIDDIR}
FILES_SUBST+=		JABBERD_USER=${JABBERD_USER}

EGDIR=			${PREFIX}/share/examples/jabberd
CONF_FILES+=		${EGDIR}/muc-jcr.xml ${PKG_SYSCONFDIR}/muc-jcr.xml

INSTALLATION_DIRS=	bin

post-extract:
	@${MV} ${XMLCONFIG} ${XMLCONFIG}.in

pre-configure:
	@${SED}	-e "s|\(<logdir>\)[^<]*|\1${JABBERD_LOGDIR}|g" \
		-e "s|\(<pidfile>\).|\1${JABBERD_PIDDIR}|g" \
		-e "s|\(<spool>\).|\1${JABBERD_SPOOLDIR}|g" \
		${XMLCONFIG}.in > ${XMLCONFIG}

pre-build:
	cd ${WRKDIR} ; ${PAX} -rw -pe ${DISTNAME} ${WRKSRC}

post-build:
	${CP} ${WRKSRC}/src/main.c ${WRKSRC}/src/jcomp.mk ${SUBWRKSRC}
	cd ${SUBWRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} -f jcomp.mk

do-install:
	${INSTALL_PROGRAM} ${SUBWRKSRC}/mu-conference ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}/muc-jcr.xml ${EGDIR}

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

