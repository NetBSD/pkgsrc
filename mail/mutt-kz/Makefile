# $NetBSD: Makefile,v 1.11 2016/02/22 12:13:26 wiz Exp $

DISTNAME=	mutt-kz-1.5.23.1-rc1
PKGREVISION=	3
PKGNAME=	${DISTNAME:S/-rc/rc/}
CATEGORIES=	mail
MASTER_SITES=	ftp://redcrew.org/pub/mutt-kz/v1.5.23.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://kzak.redcrew.org/doku.php?id=mutt:start
COMMENT=		Text-based MIME mail client with notmuch, PGP & S/MIME support
LICENSE=		gnu-gpl-v2 OR gnu-gpl-v3 # or newer

CONFIGURE_ARGS+=	--enable-notmuch

# On case-insensitive file systems like on OS X, version.sh is used
# to re-create VERSION, and fails. Make sure VERSION is newer than
# version.sh to avoid this.
pre-build:
	${TOUCH} ${WRKSRC}/VERSION

.include "../../mail/mutt/Makefile.common"

DEINSTALL_SRC=		${.CURDIR}/../../mail/mutt/DEINSTALL
INSTALL_SRC=		${.CURDIR}/../../mail/mutt/INSTALL

.include "../../mail/notmuch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
