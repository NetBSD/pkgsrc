# $NetBSD: Makefile,v 1.1 2014/01/12 17:43:37 wiz Exp $

DISTNAME=       mutt-kz-1.5.22.1-rc1
PKGNAME=        ${DISTNAME:S/-rc/rc/}
CATEGORIES=     mail
MASTER_SITES=   ftp://redcrew.org/pub/mutt-kz/v1.5.22.1/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://kzak.redcrew.org/doku.php?id=mutt:start
COMMENT=		Text-based MIME mail client with notmuch, PGP & S/MIME support
LICENSE=		gnu-gpl-v2 OR gnu-gpl-v3 # or newer

CONFIGURE_ARGS+=	--enable-notmuch

.include "../../mail/mutt-devel/Makefile.common"

DEINSTALL_SRC=		${.CURDIR}/../../mail/mutt-devel/DEINSTALL
INSTALL_SRC=		${.CURDIR}/../../mail/mutt-devel/INSTALL

.include "../../mail/notmuch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
