# $NetBSD: Makefile,v 1.19.8.1 2002/12/22 08:29:19 agc Exp $
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

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--program-prefix=g
CONFIGURE_ARGS+=	--with-catgets

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
