# $NetBSD: Makefile,v 1.1.1.1 2001/08/21 12:00:14 rh Exp $
#

DISTNAME=	pen-0.2.0
CATEGORIES=	net
MASTER_SITES=	http://siag.nu/pub/pen/					\
		ftp://siag.nu/pub/pen/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://siag.nu/pen/
COMMENT=	load balancer for "simple" tcp based protocols

NO_CONFIGURE=	YES

do-install:
.for prg in pen mergelogs
		${INSTALL_PROGRAM} ${WRKSRC}/${prg} ${PREFIX}/sbin
		${INSTALL_MAN} ${WRKSRC}/${prg}.1 ${PREFIX}/man/man8/${prg}.8
.endfor
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pen
.for doc in COPYING ChangeLog README
		${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/pen
.endfor

.include "../../mk/bsd.pkg.mk"
