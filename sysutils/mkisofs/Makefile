# $NetBSD: Makefile,v 1.17 2000/12/20 17:13:21 wiz Exp $
#

DISTNAME=       mkisofs-1.11.3
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.cdrom.com/pub/linux/tsx-11/packages/mkisofs/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://andante.jic.com/mkisofs.html

IGNORE=		"${PKGNAME} is now part of the cdrecord package" \
		"(someone will maybe split mkisofs out from cdrecord)."

GNU_CONFIGURE=	yes
ALL_TARGET=	World

post-patch:
	@cd ${WRKSRC}; \
	${GREP} -v ^# mkisofs.8 >mkisofs.$$$$; \
	${MV} mkisofs.$$$$ mkisofs.8

.include "../../mk/bsd.pkg.mk"
