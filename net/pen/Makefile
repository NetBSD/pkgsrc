# $NetBSD: Makefile,v 1.4 2003/04/13 11:43:25 cjep Exp $
#

DISTNAME=	pen-0.10.1
CATEGORIES=	net
MASTER_SITES=	http://siag.nu/pub/pen/					\
		ftp://siag.nu/pub/pen/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://siag.nu/pen/
COMMENT=	load balancer for "simple" tcp based protocols

GNU_CONFIGURE=	YES

# Avoid pen complaining on NetBSD
CONFIGURE_ARGS+=	--with-fd_setsize=2048

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
