# $NetBSD: Makefile,v 1.11 1999/09/29 23:48:14 hubertf Exp $
# FreeBSD Id: Makefile,v 1.9 1997/02/04 10:32:34 max Exp 
#

DISTNAME=	sox-12.16
CATEGORIES=	audio
MASTER_SITES=	http://metalab.unc.edu/pub/Linux/apps/sound/convert/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://home.sprynet.com/~cbagwell/sox.html

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-fast-ulaw \
		--enable-fast-alaw \
		--with-sun-audio

.include "../../mk/bsd.pkg.mk"
