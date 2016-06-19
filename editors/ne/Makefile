# $NetBSD: Makefile,v 1.18 2016/06/19 17:25:31 prlw1 Exp $

DISTNAME=	ne-3.02
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/wordprocessing/unix/ne/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	ftp://ftp.csx.cam.ac.uk/pub/software/wordprocessing/unix/ne/
COMMENT=	Terminal text editor
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-termcap

BUILD_TARGET=	build

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
