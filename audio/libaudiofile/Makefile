# $NetBSD: Makefile,v 1.15 2000/10/15 03:04:26 jlam Exp $
# FreeBSD Id: Makefile,v 1.2 1999/01/27 08:31:48 fenner Exp
#

DISTNAME=		audiofile-0.1.10
PKGNAME=		libaudiofile-0.1.10
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.68k.org./pub/michael/ \
			${MASTER_SITE_GNOME:=stable/sources/audiofile/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://andromeda.68k.org/~michael/audiofile/

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

DOCDIR=			${PREFIX}/share/doc/libaudiofile

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/docs; ${INSTALL_DATA} af* sf* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
