# $NetBSD: Makefile,v 1.2 2000/11/07 18:11:46 ad Exp $

DISTNAME=		userppp-001107
CATEGORIES=		net
MASTER_SITES=		http://www.awfulhak.org/~brian/
DISTFILES=		ppp-001107.src.tar.gz

MAINTAINER=		ad@netbsd.org
HOMEPAGE=		http://www.awfulhak.org/~brian/

WRKSRC=			${WRKDIR}/ppp-001107

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
