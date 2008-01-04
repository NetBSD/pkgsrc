# $NetBSD: Makefile,v 1.3 2008/01/04 11:55:37 ghen Exp $

DISTNAME=		policyd-1.82
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=policyd/}

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.policyd.org/
COMMENT=		Policy daemon for Postfix with greylisting and throttling

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

BUILD_TARGET=		build
MAKE_ENV+=		MYSQL_PREFIX=${BUILDLINK_PREFIX.mysql-client}

BUILD_DEFS+=		VARBASE

BINDIR=			${PREFIX}/libexec/policyd
DOCDIR=			${PREFIX}/share/doc/policyd
EGDIR=			${PREFIX}/share/examples/policyd
INSTALLATION_DIRS=	${BINDIR} ${DOCDIR} ${EGDIR}

CONF_FILES=		${EGDIR}/policyd.conf ${PKG_SYSCONFDIR}/policyd.conf

RCD_SCRIPTS=		policyd

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-build
SUBST_FILES.config=	policyd.conf
SUBST_SED.config=	-e 's,%%VARBASE%%,${VARBASE},'

FILES_SUBST+=		BINDIR=${BINDIR}
MESSAGE_SUBST+=		BINDIR=${BINDIR}
MESSAGE_SUBST+=		EGDIR=${EGDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/policyd ${DESTDIR}${BINDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/cleanup ${DESTDIR}${BINDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/stats ${DESTDIR}${BINDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/policyd.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/blacklist_helo.sql ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/whitelist.sql ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/DATABASE.mysql ${DESTDIR}${EGDIR}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
