# $NetBSD: Makefile,v 1.15 2000/06/15 12:08:10 hubertf Exp $
#

DISTNAME=       mkisofs-1.11.3
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.cdrom.com/pub/linux/tsx-11/packages/mkisofs/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://andante.jic.com/mkisofs.html

IGNORE=		"is now part of the cdrecord(-current) package" \
		"(someone maybe split mkisofs out from cdrecord)."

GNU_CONFIGURE=	yes
ALL_TARGET=	World

post-patch:
	@cd ${WRKSRC}; \
	${GREP} -v ^# mkisofs.8 >mkisofs.$$$$; \
	${MV} mkisofs.$$$$ mkisofs.8

.include "../../mk/bsd.pkg.mk"
