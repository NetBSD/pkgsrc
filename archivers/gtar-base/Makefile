# $NetBSD: Makefile,v 1.24 2002/12/22 01:34:38 wiz Exp $
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
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
CONFIGURE_ARGS+=	--with-catgets
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.if ${OPSYS} == "Darwin"
PLIST_SRC=	${.CURDIR}/PLIST.Darwin
EXTRACT_SUFX=	.tar.gz
.endif

post-patch:
	@${ECHO} '' >>${WRKSRC}/po/fr.po

post-install:
	${INSTALL_DATA} ${FILESDIR}/${GNU_PROGRAM_PREFIX}tar.1 \
		${PREFIX}/man/man1/${GNU_PROGRAM_PREFIX}tar.1

.include "../../mk/bsd.pkg.mk"
