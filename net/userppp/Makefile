# $NetBSD: Makefile,v 1.1.1.1 2000/11/07 17:26:58 ad Exp $

DISTNAME=		userppp-001107
CATEGORIES=		net
MASTER_SITES=		http://www.awfulhak.org/~brian/
DISTFILES=		ppp-001107.src.tar.gz

MAINTAINER=		ad@netbsd.org
HOMEPAGE=		http://www.awfulhak.org/~brian/

WRKSRC=			${WRKDIR}/ppp-001107

pre-install:
		${GREP} "^network:" /etc/group >/dev/null || \
		    /usr/sbin/groupadd -g 40 network

.include "../../mk/bsd.pkg.mk"
