# $NetBSD: Makefile,v 1.14 2004/01/20 12:22:22 agc Exp $

DISTNAME=		ppp-001107.src
PKGNAME=		userppp-001107
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.NetBSD.org/~ad/

MAINTAINER=		ad@NetBSD.org
HOMEPAGE=		http://www.awfulhak.org/~brian/
COMMENT=		User-PPP package as found in FreeBSD and OpenBSD

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}/${DISTNAME:S/.src//}
MANCOMPRESSED_IF_MANZ=	YES

CFLAGS+=	-fno-strict-aliasing

post-patch:
	(cd ${WRKSRC};							\
	for i in ppp/ppp.8 pppctl/pppctl.8; do \
		${SED}	-e "s,/etc/ppp,${PREFIX}/etc/ppp,"		\
			-e "s,/usr/share,${PREFIX}/share,"		\
			$$i > $$i.done; ${MV} $$i.done $$i;		\
	done)

.include "../../mk/bsd.prefs.mk"

USERPPP_GROUP?=	network
BUILD_DEFS+=	USERPPP_GROUP

USE_PKGINSTALL=	yes
PKG_GROUPS=	${USERPPP_GROUP}

.include "../../mk/bsd.pkg.mk"
