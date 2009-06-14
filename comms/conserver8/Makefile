# $NetBSD: Makefile,v 1.8 2009/06/14 07:52:51 wiz Exp $
#

DISTNAME=	conserver-8.1.16
PKGNAME=	conserver8-8.1.16
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.conserver.com/conserver/

MAINTAINER=	awrede@users.sourceforge.net
HOMEPAGE=	http://www.conserver.com/
COMMENT=	Application that allows multiple users to watch serial consoles

CONFLICTS=	conserver-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	${EGDIR} ${DOCDIR}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-master=${CONSERVER_DEFAULTHOST:Q}
CONFIGURE_ARGS+=	--with-port=${CONSERVER_DEFAULTPORT:Q}
CONFIGURE_ARGS+=	--with-regex
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ARGS+=	--with-logfile=${VARBASE:Q}/log/conserver

.include "options.mk"

BUILD_DEFS+=	CONSERVER_DEFAULTPORT CONSERVER_DEFAULTHOST VARBASE

RCD_SCRIPTS=	conserver8

TEST_TARGET=	test

DOCDIR=		${PREFIX}/share/doc/conserver
EGDIR=		${PREFIX}/share/examples/conserver
CONF_FILES=	${EGDIR}/conserver.cf ${PKG_SYSCONFDIR}/conserver.cf
CONF_FILES+=	${EGDIR}/conserver.passwd ${PKG_SYSCONFDIR}/conserver.passwd
OWN_DIRS=	${VARBASE}/consoles

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	conserver.cf/conserver.cf
SUBST_SED.conf=		-e "s,/var/consoles,${VARBASE}/consoles,"

post-install:
	set -e; for File in INSTALL README PROTOCOL; do			\
		${INSTALL_DATA} ${WRKSRC}/$${File} ${DESTDIR}${DOCDIR}/$${File};	\
	done

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
