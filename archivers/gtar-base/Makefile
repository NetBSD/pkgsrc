# $NetBSD: Makefile,v 1.21 2002/11/20 16:57:54 bouyer Exp $
#

DISTNAME=       tar-1.13.25
PKGNAME=	gtar-base-1.13.25
SVR4_PKGNAME=	gtarb
CATEGORIES=	archivers
MASTER_SITES=	ftp://alpha.gnu.org/gnu/tar/ \
		ftp://ftp.sunsite.org.uk/Mirrors/alpha.gnu.org/gnu/tar/ \
		ftp://ftp.funet.fi/pub/mirrors/alpha.gnu.org/gnu/tar/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The GNU tape archiver with remote magnetic tape support

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-prefix=g --with-catgets
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST_SRC=	${.CURDIR}/PLIST.Darwin
EXTRACT_SUFX=	.tar.gz
.endif

post-patch:
	@${ECHO} '' >>${WRKSRC}/po/fr.po

post-install:
	${INSTALL_DATA} ${FILESDIR}/gtar.1 ${PREFIX}/man/man1/gtar.1

.include "../../mk/bsd.pkg.mk"
