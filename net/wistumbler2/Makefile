# $NetBSD: Makefile,v 1.1.1.1 2003/12/03 19:11:01 xtraeme Exp $

DISTNAME=	wistumbler2.00-pre3
PKGNAME=	${DISTNAME:S/wistumbler/wistumbler-/}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nopcode.org/prj/wistumbler2/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.nopcode.org/?t=wistumbler2
COMMENT=	Fork of original WaveLAN/IEEE network stumbler

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
MANCOMPRESSED=	YES

NOT_FOR_PLATFORM=	NetBSD-[01].[012345]*-* 
ONLY_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-*

WISTUMBLER2_USES_GTK?=	yes

BUILD_DEFS+=		WISTUMBLER2_USES_GTK

.include "../../mk/bsd.prefs.mk"

.if !empty(WISTUMBLER2_USES_GTK:M[Yy][Ee][Ss])
.include "../../x11/gtk2/buildlink2.mk"
.else	
CONFIGURE_ENV+=		USE_GTK=0
.endif

.include "../../mk/bsd.pkg.mk"
