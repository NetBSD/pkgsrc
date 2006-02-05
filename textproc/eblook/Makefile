# $NetBSD: Makefile,v 1.15 2006/02/05 23:11:01 joerg Exp $
#

DISTNAME=	eblook-1.6.1
PKGREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/edict/eblook/
COMMENT=	Interactive command-line interface for EPWING electric dictionaries

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
INFO_FILES=	eblook.info
CONFIGURE_ARGS+=--with-eb-conf=${PKG_SYSCONFDIR.eb}/eb.conf

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/eb/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
