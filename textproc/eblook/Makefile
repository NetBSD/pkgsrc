# $NetBSD: Makefile,v 1.16 2006/04/07 18:59:30 jlam Exp $
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
LIBS+=		${BUILDLINK_LDADD.iconv}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/eb/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
