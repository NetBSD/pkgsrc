# $NetBSD: Makefile,v 1.20 2018/06/06 14:53:04 prlw1 Exp $

DISTNAME=	ne-3.15
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/wordprocessing/unix/ne/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	ftp://ftp.csx.cam.ac.uk/pub/software/wordprocessing/unix/ne/
COMMENT=	Terminal text editor
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-termcap
MAKE_ENV+=		SHELL=${SH}

BUILD_TARGET=	build

.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
