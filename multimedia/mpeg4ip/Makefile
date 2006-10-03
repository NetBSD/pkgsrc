# $NetBSD: Makefile,v 1.10 2006/10/03 12:55:32 tron Exp $

DISTNAME=		mpeg4ip-1.5
PKGREVISION=		2
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mpeg4ip/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mpeg4ip.sourceforge.net/
COMMENT=		Tools for streaming video and audio

CONFLICTS+=		faad2<2.0nb6

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	bootstrap
OVERRIDE_DIRDEPTH=	3		# */*/*/libtool

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	MPEG4IPSDL="@comment "
.else
PLIST_SUBST+=	MPEG4IPSDL=
.endif

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
