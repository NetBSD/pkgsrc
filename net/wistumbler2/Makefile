# $NetBSD: Makefile,v 1.7 2004/10/20 22:17:31 xtraeme Exp $

DISTNAME=	wistumbler2.00-pre9
PKGNAME=	${DISTNAME:S/wistumbler/wistumbler-/}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nopcode.org/prj/wistumbler2/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.nopcode.org/?t=wistumbler2
COMMENT=	Fork of original WaveLAN/IEEE network stumbler

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES
MANCOMPRESSED=	YES
CONFIGURE_ENV+=	PREFIX=${PREFIX}

NOT_FOR_PLATFORM=	NetBSD-[01].[012345]*-*
ONLY_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-* OpenBSD-*-*

WISTUMBLER2_USES_GTK?=	yes

BUILD_DEFS+=		WISTUMBLER2_USES_GTK

.include "../../mk/bsd.prefs.mk"

.if !empty(WISTUMBLER2_USES_GTK:M[Yy][Ee][Ss])
USE_X11=		yes
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ENV+=		USE_GTK=0
.endif

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
