# $NetBSD: Makefile,v 1.23 2014/10/09 14:07:01 wiz Exp $
#

DISTNAME=	eblook-1.6.1
PKGREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/edict/eblook/
COMMENT=	Interactive command-line interface for EPWING electric dictionaries

GNU_CONFIGURE=	YES
INFO_FILES=	yes
CONFIGURE_ARGS+=--with-eb-conf=${PKG_SYSCONFDIR}/eb.conf
LIBS+=		${BUILDLINK_LDADD.iconv}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/eb/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
