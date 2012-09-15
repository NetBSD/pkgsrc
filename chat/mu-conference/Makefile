# $NetBSD: Makefile,v 1.27 2012/09/15 10:03:52 obache Exp $

DISTNAME=	mu-conference_0.8
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	http://download.gna.org/mu-conference/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jabber.terrapin.com/JCR/
COMMENT=	Implementation of the XEP-0045 Multi-User Chat protocol
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake pkg-config
LDFLAGS+=		-L${BUILDLINK_PREFIX.expat}/lib
LDFLAGS+=		-L${BUILDLINK_PREFIX.libidn}/lib
LDFLAGS.SunOS+=		-lsocket -lnsl

PKG_SYSCONFSUBDIR=	jabberd
RCD_SCRIPTS=		muc

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		JABBERD_LOGDIR JABBERD_PIDDIR
JABBERD_USER?=		jabberd
PKG_USERS_VARS+=	JABBERD_USER

FILES_SUBST+=		JABBERD_PIDDIR=${JABBERD_PIDDIR}
FILES_SUBST+=		JABBERD_USER=${JABBERD_USER}

EGDIR=			${PREFIX}/share/examples/jabberd
CONF_FILES+=		${EGDIR}/muc.xml ${PKG_SYSCONFDIR}/muc.xml

INSTALLATION_DIRS=	bin share/examples/jabberd

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_MESSAGE.config=	Fixing configuration file.
SUBST_FILES.config=	muc-default.xml
SUBST_SED.config=	-e 's|\(<logdir>\)[^<]*|\1${JABBERD_LOGDIR}|g'
SUBST_SED.config+=	-e 's|\(<pidfile>\).|\1${JABBERD_PIDDIR}|g'
SUBST_SED.config+=	-e 's|\(<spool>\)./spool|\1${JABBERD_SPOOLDIR}|g'
SUBST_SED.config+=	-e 's|\(<stylesheet>\)..|\1${EGDIR}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mu-conference ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mu-conference.sql ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/muc-default.xml ${DESTDIR}${EGDIR}/muc.xml
	${INSTALL_DATA} ${WRKSRC}/style.css ${DESTDIR}${EGDIR}/

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
