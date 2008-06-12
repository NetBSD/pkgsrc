# $NetBSD: Makefile,v 1.4 2008/06/12 02:14:21 joerg Exp $
#

DISTNAME=		acr-0.4
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.nopcode.org/prj/acr/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://news.nopcode.org/pancake/acr.html
COMMENT=		Autoconf replacement

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

INSTALL_MAKE_FLAGS=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR} \
			DATADIR=${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
