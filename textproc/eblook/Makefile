# $NetBSD: Makefile,v 1.1.1.1 2002/06/12 01:31:02 uebayasi Exp $
#

DISTNAME=	eblook-1.5.1
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://openlab.ring.gr.jp/edict/eblook/
COMMENT=	interactive command-line interface for EPWING electirc dictionaries

USE_BUILDLINK_ONLY=	# defined

GNU_CONFIGURE=	yes

.include "../../textproc/eb/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
