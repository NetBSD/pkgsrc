# $NetBSD: Makefile,v 1.6 2012/01/23 20:49:21 joerg Exp $
#

DISTNAME=		acr-0.4
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.nopcode.org/prj/acr/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://news.nopcode.org/pancake/acr.html
COMMENT=		Autoconf replacement

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

INSTALL_MAKE_FLAGS=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR} \
			DATADIR=${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
