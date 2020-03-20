# $NetBSD: Makefile,v 1.5 2020/03/20 11:58:19 nia Exp $
#

DISTNAME=		heirloom-sh-050706
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heirloom/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		http://heirloom.sourceforge.net/
COMMENT=		Traditional Unix shell derived from OpenSolaris code
LICENSE=		cddl-1.0

.include "../../mk/bsd.prefs.mk"

CPPFLAGS.Linux+=	-D_GNU_SOURCE -D_FILE_OFFSET_BITS=64L

PKG_SHELL=		${PREFIX}/heirloom/bin/jsh

PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${PKGDOCDIR}

DOC_FILES=	CHANGES CALDERA.LICENSE OPENSOLARIS.LICENSE README

MAKE_FILE=	makefile
MAKE_FLAGS+=	ROOT=${DESTDIR}
MAKE_FLAGS+=	SV3BIN=${PREFIX}/heirloom/bin
MAKE_FLAGS+=	MANDIR=${PREFIX}/heirloom/man
MAKE_FLAGS+=	UCBINST=${INSTALL_DATA:Q}
MAKE_FLAGS+=	STRIP=true #${STRIP}
MAKE_FLAGS+=	WARN=
MAKE_FLAGS+=	WERROR=
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PKGDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
