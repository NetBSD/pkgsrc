# $NetBSD: Makefile,v 1.14 1999/05/07 08:09:06 ross Exp $
#

DISTNAME=       mkisofs-1.11.3
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.cdrom.com/pub/linux/tsx-11/packages/mkisofs/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://andante.jic.com/mkisofs.html

GNU_CONFIGURE=	yes
ALL_TARGET=	World

post-patch:
	@cd ${WRKSRC}; \
	${GREP} -v ^# mkisofs.8 >mkisofs.$$$$; \
	${MV} mkisofs.$$$$ mkisofs.8

.include "../../mk/bsd.pkg.mk"
