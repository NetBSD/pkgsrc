# $NetBSD: Makefile,v 1.8 2004/10/30 15:24:02 adrianp Exp $

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
USE_PKGINSTALL=	YES
CONFIGURE_ENV+=	PREFIX=${PREFIX}

NOT_FOR_PLATFORM=	NetBSD-[01].[012345]*-*
ONLY_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-* OpenBSD-*-*

WISTUMBLER2_USES_GTK?=	yes

BUILD_DEFS+=		WISTUMBLER2_USES_GTK

CONF_FILES=	${PREFIX}/share/wistumber2/wistumber2.conf \
		${PKG_SYSCONFDIR}/wistumber2.conf

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	src/userconf.c 
SUBST_SED.conf=		-e "s|/etc|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.conf=	"Fixing configuration files."

.include "../../mk/bsd.prefs.mk"

.if !empty(WISTUMBLER2_USES_GTK:M[Yy][Ee][Ss])
USE_X11=		yes
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ENV+=		USE_GTK=0
.endif

post-extract:
	@${CHMOD} ${PKGDIRMODE} ${WRKSRC}/doc
	@${CHMOD} ${PKGDIRMODE} ${WRKSRC}/img

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
