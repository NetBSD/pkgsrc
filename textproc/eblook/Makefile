# $NetBSD: Makefile,v 1.18 2007/04/27 04:08:19 uebayasi Exp $
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
INFO_FILES=	# PLIST
CONFIGURE_ARGS+=--with-eb-conf=${PKG_SYSCONFDIR}/eb.conf
LIBS+=		${BUILDLINK_LDADD.iconv}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/eb/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
