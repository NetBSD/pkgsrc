# $NetBSD: Makefile,v 1.3 2003/03/27 17:53:20 wiz Exp $
#

DISTNAME=	pen-0.10.0
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
.for doc in CONTROL COPYING ChangeLog HOWTO README
		${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/pen
.endfor

.include "../../mk/bsd.pkg.mk"
