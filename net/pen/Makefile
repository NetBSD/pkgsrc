# $NetBSD: Makefile,v 1.2 2001/09/13 15:09:38 rh Exp $
#

DISTNAME=	pen-0.4.0
CATEGORIES=	net
MASTER_SITES=	http://siag.nu/pub/pen/					\
		ftp://siag.nu/pub/pen/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://siag.nu/pen/
COMMENT=	load balancer for "simple" tcp based protocols

GNU_CONFIGURE=	YES

post-install:
#.for prg in pen mergelogs
#		${INSTALL_PROGRAM} ${WRKSRC}/${prg} ${PREFIX}/sbin
#		${INSTALL_MAN} ${WRKSRC}/${prg}.1 ${PREFIX}/man/man8/${prg}.8
#.endfor
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pen
.for doc in COPYING ChangeLog README
		${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/pen
.endfor

.include "../../mk/bsd.pkg.mk"
