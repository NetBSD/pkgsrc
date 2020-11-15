# $NetBSD: Makefile,v 1.73 2020/11/15 14:26:24 fox Exp $

DISTNAME=	ircd-hybrid-8.2.35
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ircd-hybrid/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ircd-hybrid.com/
COMMENT=	IRC server with many options
LICENSE=	gnu-gpl-v2

CONFLICTS+=	ircu-[0-9]*

USE_LIBTOOL=	yes

GNU_CONFIGURE=	YES
BUILD_DEFS+=	VARBASE IRCD_HYBRID_IRC_USER IRCD_HYBRID_IRC_GROUP

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	ircd-hybrid
RCD_SCRIPTS=		ircd-hybrid

DOCDIR=			share/doc/ircd-hybrid

INSTALLATION_DIRS+=	${DOCDIR} ${DOCDIR}/doc ${DOCDIR}/doc/technical

OWN_DIRS_PERMS+=	${VARBASE}/log/ircd-hybrid \
			${IRCD_HYBRID_IRC_USER} ${IRCD_HYBRID_IRC_GROUP} 0770
OWN_DIRS_PERMS+=	${VARBASE}/log/ircd-hybrid/lib \
			${IRCD_HYBRID_IRC_USER} ${IRCD_HYBRID_IRC_GROUP} 0770
OWN_DIRS_PERMS+=	${VARBASE}/log/ircd-hybrid/logs \
			${IRCD_HYBRID_IRC_USER} ${IRCD_HYBRID_IRC_GROUP} 0770

FILES_SUBST+=		IRCD_HYBRID_IRC_USER=${IRCD_HYBRID_IRC_USER}
FILES_SUBST+=		IRCD_HYBRID_IRC_GROUP=${IRCD_HYBRID_IRC_GROUP}
FILES_SUBST+=		VARBASE=${VARBASE}

PKG_GROUPS=		${IRCD_HYBRID_IRC_GROUP}
PKG_USERS=		${IRCD_HYBRID_IRC_USER}:${IRCD_HYBRID_IRC_GROUP}

PKG_USERS_VARS+=	IRCD_HYBRID_IRC_USER
PKG_GROUPS_VARS+=	IRCD_HYBRID_IRC_GROUP

SUBST_CLASSES+=		mpaths
SUBST_MESSAGE.mpaths=	Fixing hardcoded paths in ircd(8)
SUBST_STAGE.mpaths=	pre-configure
SUBST_FILES.mpaths=	doc/ircd.8
SUBST_SED.mpaths+=	-e "s|/usr/share/ircd|${PKG_SYSCONFDIR}|g"
SUBST_SED.mpaths+=	-e "s|/var/log|${VARBASE}/log/ircd-hybrid|g"

SUBST_CLASSES+=		rpaths
SUBST_MESSAGE.rpaths=	Adjusting paths in reference.conf
SUBST_STAGE.rpaths=	pre-configure
SUBST_FILES.rpaths=	doc/reference.conf
SUBST_SED.rpaths+=	-e "s|var/log|${VARBASE}/log/ircd-hybrid/logs|g"
SUBST_SED.rpaths+=	-e "s|var/lib|${VARBASE}/log/ircd-hybrid/lib|g"

SUBST_CLASSES+=		bpaths
SUBST_MESSAGE.bpaths=	Fixing hardcoded build paths.
SUBST_STAGE.bpaths=	post-configure
SUBST_FILES.bpaths=	include/defaults.h
SUBST_SED.bpaths+=	-e "s|LOGPATH \"/ircd.log\"|\"${VARBASE}/log/ircd-hybrid/ircd.log\"|g"
SUBST_SED.bpaths+=	-e "s|RUNPATH \"/ircd.pid\"|\"${VARBASE}/run/ircd-hybrid/ircd.pid\"|g"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/log/ircd-hybrid

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/tools/README.mkpasswd \
		${DESTDIR}${PREFIX}/${DOCDIR}/README.ircd-hybrid-mkpasswd

	${INSTALL_DATA} ${WRKSRC}/doc/*.conf ${DESTDIR}${PREFIX}/${DOCDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/${DOCDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/doc/technical/*.txt ${DESTDIR}${PREFIX}/${DOCDIR}/doc/technical

	${MV} ${DESTDIR}${PREFIX}/bin/mkpasswd \
		${DESTDIR}${PREFIX}/bin/ircd-hybrid-mkpasswd

.include "../../mk/bsd.pkg.mk"
