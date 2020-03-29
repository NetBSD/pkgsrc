# $NetBSD: Makefile,v 1.27 2020/03/29 06:01:31 rillig Exp $

DISTNAME=		ppp-001107.src
PKGNAME=		userppp-001107
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://www.NetBSD.org/~ad/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.awfulhak.org/~brian/
COMMENT=		User-PPP package as found in FreeBSD and OpenBSD

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}/${DISTNAME:S/.src//}
MANCOMPRESSED_IF_MANZ=	YES

PKG_SYSCONFSUBDIR=	ppp

CFLAGS+=		-fno-strict-aliasing

SUBST_CLASSES+=		cfgdir
SUBST_STAGE.cfgdir=	do-configure
SUBST_FILES.cfgdir=	ppp/ppp.8 pppctl/pppctl.8
SUBST_SED.cfgdir=	-e "s,/etc/ppp,${PKG_SYSCONFDIR},"
SUBST_SED.cfgdir+=	-e "s,/usr/share,${PREFIX}/share,"

.include "../../mk/bsd.prefs.mk"

SPECIAL_PERMS+=	sbin/ppp ${REAL_ROOT_USER} ${USERPPP_GROUP} 04554

USERPPP_GROUP?=	network
MAKE_ENV+=	USERPPP_GROUP=${USERPPP_GROUP:Q} BINOWN=${ROOT_USER}

PKG_GROUPS=	${USERPPP_GROUP}

PKG_GROUPS_VARS+=	USERPPP_GROUP
BUILD_DEFS+=		USERPPP_GROUP

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 sbin
INSTALLATION_DIRS+=	share/examples/ppp

.include "../../mk/bsd.pkg.mk"
