# $NetBSD: Makefile,v 1.13 2000/12/02 02:14:11 wiz Exp $
# FreeBSD Id: Makefile,v 1.9 1997/02/04 10:32:34 max Exp 
#

DISTNAME=	sox-12.17.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/sound/convert/} \
		${MASTER_SITE_SOURCEFORGE:=sox/} \
		http://home.sprynet.com/~cbagwell/

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
