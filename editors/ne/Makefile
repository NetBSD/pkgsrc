# $NetBSD: Makefile,v 1.21 2019/06/08 10:40:56 rillig Exp $

DISTNAME=	ne-3.15
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/wordprocessing/unix/ne/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	ftp://ftp.csx.cam.ac.uk/pub/software/wordprocessing/unix/ne/
COMMENT=	Terminal text editor
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-termcap
MAKE_ENV+=		SHELL=${SH:Q}

BUILD_TARGET=	build

.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
