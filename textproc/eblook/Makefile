# $NetBSD: Makefile,v 1.9 2003/08/03 00:36:50 seb Exp $
#

DISTNAME=	eblook-1.5.1
PKGREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/edict/eblook/
COMMENT=	Interactive command-line interface for EPWING electric dictionaries

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_NEW_TEXINFO=	YES
INFO_FILES=	eblook.info

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/eb/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
