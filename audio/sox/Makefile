# $NetBSD: Makefile,v 1.12 1999/10/26 01:31:01 hubertf Exp $
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
		--with-sun-audio \
		--without-oss-dsp

pre-build:
		cd ${WRKSRC} ; \
		[ -f play.BAK ] || ${MV} play play.BAK ; \
		${SED} \
			-e 's|@PREFIX@|${PREFIX}|g' \
			< play.BAK >play

.include "../../mk/bsd.pkg.mk"
