# $NetBSD: Makefile,v 1.20 2002/08/25 21:49:06 jlam Exp $
#

DISTNAME=       tar-1.12
PKGNAME=	gtar-base-1.12
SVR4_PKGNAME=	gtarb
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=tar/}
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The GNU tape archiver with remote magnetic tape support

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-prefix=g --with-catgets
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PLIST_SRC=	${.CURDIR}/PLIST.NetBSD
.elif ${OPSYS} == "Darwin"
PLIST_SRC=	${.CURDIR}/PLIST.Darwin
EXTRACT_SUFX=	.tar.gz
.endif

post-patch:
	@${ECHO} '' >>${WRKSRC}/po/fr.po

post-install:
	${INSTALL_DATA} ${FILESDIR}/gtar.1 ${PREFIX}/man/man1/gtar.1

.include "../../mk/bsd.pkg.mk"
