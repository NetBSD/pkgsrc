# $NetBSD: Makefile,v 1.34 2004/04/05 18:38:43 reed Exp $
#

DISTNAME=       tar-1.13.25
PKGNAME=	gtar-base-1.13.25
PKGREVISION=	2
SVR4_PKGNAME=	gtarb
CATEGORIES=	archivers
MASTER_SITES=	ftp://alpha.gnu.org/gnu/tar/ \
		ftp://ftp.sunsite.org.uk/Mirrors/alpha.gnu.org/gnu/tar/ \
		ftp://ftp.funet.fi/pub/mirrors/alpha.gnu.org/gnu/tar/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The GNU tape archiver with remote magnetic tape support

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX) && ${GNU_PROGRAM_PREFIX} != ""
GTAR_PROGRAM_PREFIX?=	${GNU_PROGRAM_PREFIX}
.else
GTAR_PROGRAM_PREFIX?=	g
.endif

.if ${GTAR_PROGRAM_PREFIX} == ""
# pax installs a "tar" also
CONFLICTS+=		pax-[0-9]*
.else
CONFIGURE_ARGS+=	--program-prefix=${GTAR_PROGRAM_PREFIX}
.endif

CONFIGURE_ARGS+=	--with-catgets
PLIST_SUBST+=		GTAR_PROGRAM_PREFIX=${GTAR_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX
BUILD_DEFS+=		GTAR_PROGRAM_PREFIX

.if ${GTAR_PROGRAM_PREFIX} != "g"
PLIST_SUBST+=           GTAR_LINK=""
.else
PLIST_SUBST+=           GTAR_LINK="@comment "
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/po/fr.po

post-install:
	${INSTALL_DATA} ${FILESDIR}/gtar.1 \
		${PREFIX}/man/man1/${GTAR_PROGRAM_PREFIX}tar.1
.if ${GTAR_PROGRAM_PREFIX} != "g"
	${LN} -sf ${GTAR_PROGRAM_PREFIX}tar ${PREFIX}/bin/gtar
.endif

.include "../../mk/bsd.pkg.mk"
