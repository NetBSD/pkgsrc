# $NetBSD: Makefile,v 1.2.2.2 2002/06/23 19:01:35 jlam Exp $
#

DISTNAME=	eblook-1.5.1
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://openlab.ring.gr.jp/edict/eblook/
COMMENT=	interactive command-line interface for EPWING electric dictionaries

USE_BUILDLINK_ONLY=	# defined

GNU_CONFIGURE=	yes

.include "../../textproc/eb/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
