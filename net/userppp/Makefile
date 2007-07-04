# $NetBSD: Makefile,v 1.22 2007/07/04 20:54:54 jlam Exp $

DISTNAME=		ppp-001107.src
PKGNAME=		userppp-001107
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.NetBSD.org/~ad/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.awfulhak.org/~brian/
COMMENT=		User-PPP package as found in FreeBSD and OpenBSD

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}/${DISTNAME:S/.src//}
MANCOMPRESSED_IF_MANZ=	YES

CFLAGS+=	-fno-strict-aliasing
# fix build on -current for wrong is* arguments (char instead of unsigned char)
BUILDLINK_TRANSFORM+=	rm:-Werror

post-patch:
	(cd ${WRKSRC};							\
	for i in ppp/ppp.8 pppctl/pppctl.8; do \
		${SED}	-e "s,/etc/ppp,${PREFIX}/etc/ppp,"		\
			-e "s,/usr/share,${PREFIX}/share,"		\
			$$i > $$i.done; ${MV} $$i.done $$i;		\
	done)

.include "../../mk/bsd.prefs.mk"

USERPPP_GROUP?=	network
MAKE_ENV+=	USERPPP_GROUP=${USERPPP_GROUP:Q}

PKG_GROUPS=	${USERPPP_GROUP}

PKG_GROUPS_VARS+=	USERPPP_GROUP

.include "../../mk/bsd.pkg.mk"
