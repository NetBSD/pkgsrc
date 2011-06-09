# $NetBSD: Makefile,v 1.7 2011/06/09 11:50:17 drochner Exp $
#

DISTNAME=		gplcver-2.12a.src
PKGNAME=		gplcver-2.12a
CATEGORIES=		cad
#MASTER_SITES=		http://www.pragmatic-c.com/gpl-cver/downloads/
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gplcver/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.pragmatic-c.com/gpl-cver/
COMMENT=		Verilog simulator

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DIRS=		src
MAKE_FILE=		makefile.freebsd
BUILDLINK_LIBS.dl=	${BUILDLINK_LDADD.dl}

INSTALLATION_DIRS=	bin lib/gplcver/pli_incs

.include "../../mk/dlopen.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cver ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pli_incs/*.h \
		${DESTDIR}${PREFIX}/lib/gplcver/pli_incs

.include "../../mk/bsd.pkg.mk"
