# $NetBSD: Makefile,v 1.3 2002/10/05 03:07:08 wiz Exp $
#

DISTNAME=	eblook-1.5.1
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://openlab.ring.gr.jp/edict/eblook/
COMMENT=	interactive command-line interface for EPWING electric dictionaries

USE_BUILDLINK2=	# defined

GNU_CONFIGURE=	yes

.include "../../textproc/eb/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
