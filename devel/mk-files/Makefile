# $NetBSD: Makefile,v 1.1.1.1 2001/05/25 12:33:34 agc Exp $
#

DISTNAME=       mk-1.2.2
PKGNAME=	mk-files-1.2.2
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.netbsd.org/pub/incoming/sjg/

MAINTAINER=	sjg@netbsd.org
HOMEPAGE=	http://www.quick.com.au/help/sjg/bmake.html
COMMENT=	portable *.mk files for the NetBSD portable bmake utility

WRKSRC=		${WRKDIR}/mk

NO_CONFIGURE=	yes
NO_BUILD=	yes

MKFILES=	autodep.mk bsd.dep.mk bsd.doc.mk bsd.lib.mk bsd.man.mk
MKFILES+=	bsd.nls.mk bsd.obj.mk bsd.own.mk bsd.prog.mk bsd.subdir.mk
MKFILES+=	dep.mk doc.mk lib.mk man.mk nls.mk obj.mk own.mk prog.mk
MKFILES+=	subdir.mk

do-install:
	${BSD_INSTALL_DATA} ${WRKSRC}/`uname -s`.sys.mk ${PREFIX}/share/mk/sys.mk
	for f in ${MKFILES}; do						\
		${BSD_INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/mk/;	\
	done

.include "../../mk/bsd.pkg.mk"
