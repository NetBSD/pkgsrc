# $NetBSD: Makefile,v 1.17 2002/07/12 19:30:50 mycroft Exp $
# FreeBSD Id: Makefile,v 1.9 1997/02/04 10:32:34 max Exp 
#

DISTNAME=	sox-12.17.3
CATEGORIES=	audio
MASTER_SITES=	http://home.sprynet.com/~cbagwell/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://home.sprynet.com/~cbagwell/sox.html
COMMENT=	SOund eXchange - universal sound sample translator

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-fast-ulaw \
			--enable-fast-alaw \
			--with-sun-audio \
			--without-oss-dsp

.include "../../mk/bsd.pkg.mk"
