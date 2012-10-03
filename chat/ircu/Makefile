# $NetBSD: Makefile,v 1.35 2012/10/03 00:02:38 asau Exp $
#

DISTNAME=	ircu2.10.12.12
PKGNAME=	${DISTNAME:S/ircu2/ircu-2/}
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=undernet-ircu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://coder-com.undernet.org/
COMMENT=	Internet Relay Chat server customized for Undernet

CONFLICTS+=	ircd-hybrid-[0-9]*

GNU_CONFIGURE=	YES
USE_TOOLS+=	lex yacc

CONFIGURE_ARGS+=	--bindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--with-cpath=${PKG_SYSCONFDIR}/ircd.conf
CONFIGURE_ARGS+=	--with-dpath=${DATADIR}
CONFIGURE_ARGS+=	--with-lpath=${DATADIR}/ircd.log
CONFIGURE_ARGS+=	--with-mode=555
CONFIGURE_ARGS+=	--with-owner=0
CONFIGURE_ARGS+=	--with-group=0
CONFIGURE_ARGS+=	--with-symlink=no

PKG_SYSCONFSUBDIR=	ircd

.include "../../mk/bsd.prefs.mk"

IRCD_USER?=		ircd
IRCD_GROUP?=		ircd
PKG_USERS_VARS+=	IRCD_USER
PKG_GROUPS_VARS+=	IRCD_GROUP

DATADIR=		${VARBASE}/ircd
OWN_DIRS_PERMS=		${DATADIR} ${IRCD_USER} ${IRCD_GROUP} 0700
EGDIR=			${PREFIX}/share/examples/ircd
DOCDIR=			${PREFIX}/share/doc/ircd
BUILD_DEFS+=		VARBASE

CONF_FILES_PERMS+=	${EGDIR}/example.conf ${PKG_SYSCONFDIR}/ircd.conf \
			${IRCD_USER} ${IRCD_GROUP} 0600

PKG_SYSCONFDIR_PERMS=	${IRCD_USER} ${IRCD_GROUP} 0700

RCD_SCRIPTS=		ircd

FILES_SUBST+=		IRCD_USER=${IRCD_USER:Q}
MESSAGE_SUBST+=		IRCD_USER=${IRCD_USER}
MESSAGE_SUBST+=		IRCD_GROUP=${IRCD_GROUP}

PKG_GROUPS=		${IRCD_GROUP}
PKG_USERS=		${IRCD_USER}:${IRCD_GROUP}

PKG_GECOS.${IRCD_USER}=	IRC server user
PKG_SHELL.${IRCD_USER}=	${SH}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 sbin ${DOCDIR} ${EGDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ircd/ircd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ircd/umkpasswd ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ircd/convert-conf \
		${DESTDIR}${PREFIX}/bin/uconvert-conf
	${INSTALL_MAN} ${WRKSRC}/doc/ircd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE.NOTES ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/readme.* ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
