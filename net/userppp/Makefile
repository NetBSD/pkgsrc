# $NetBSD: Makefile,v 1.7 2001/02/17 18:19:52 wiz Exp $

DISTNAME=		ppp-001107.src
PKGNAME=		userppp-001107
CATEGORIES=		net
MASTER_SITES=		http://www.netbsd.org/~ad/

MAINTAINER=		ad@netbsd.org
HOMEPAGE=		http://www.awfulhak.org/~brian/
COMMENT=		User-PPP package as found in FreeBSD and OpenBSD

ONLY_FOR_PLATFORM=	NetBSD-*-*

MANCOMPRESSED_IF_MANZ=	YES
WRKSRC=			${WRKDIR}/${DISTNAME:S/.src//}

post-patch:
		(cd ${WRKSRC}; \
		for i in ppp/ppp.8 pppctl/pppctl.8; do \
			${CP} $$i $$i.bak; \
			${SED} s@/etc/ppp@${PREFIX}/etc/ppp@ < $$i.bak | \
			    ${SED} s@/usr/share@${PREFIX}/share@ > $$i; \
		done)

pre-install:
		${GREP} "^network:" /etc/group >/dev/null || \
		    /usr/sbin/groupadd -g 40 network

.include "../../mk/bsd.pkg.mk"
