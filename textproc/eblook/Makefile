# $NetBSD: Makefile,v 1.7 2003/07/17 22:54:13 grant Exp $
#

DISTNAME=	eblook-1.5.1
PKGREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/edict/eblook/
COMMENT=	interactive command-line interface for EPWING electric dictionaries

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/eb/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
