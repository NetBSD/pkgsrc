# New ports collection makefile for:    timidity
# Homepage: http://www.cgs.fi/~tt/timidity/
# Version required:     0.2i
# Date created:         17 Nov 1996
# Whom:                 ache
#
# $NetBSD: Makefile,v 1.8 1998/03/11 18:13:22 mycroft Exp $
# FreeBSD Id: Makefile,v 1.5 1997/09/07 22:08:13 ache Exp 
#

DISTNAME=       timidity-0.2i
CATEGORIES=     audio
MASTER_SITES=   ftp://ftp.cdrom.com/pub/demos/music/samples/ \
		http://www.cgs.fi/~tt/timidity/
TIINS=          dgguspat.zip
DISTFILES=      ${TIINS} ${DISTNAME}.tar.gz

MAINTAINER=     mycroft@NetBSD.ORG

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip \
		wish8.0:${PORTSDIR}/x11/tk80
RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80
LIB_DEPENDS=	ncurses.3.4:${PORTSDIR}/devel/ncurses

NO_CDROM=       "Uses copyrighted patches"

EXTRACT_ONLY=   ${DISTNAME}.tar.gz
INSTALL_TARGET= install.all
MAN1=           timidity.1

do-configure:
	@cd ${WRKSRC} && \
	${SED} "s=%PREFIX%=${PREFIX}=" < gravis.cfg > gravis.cfg.new && \
	${MV} gravis.cfg.new gravis.cfg

post-install:
	cd ${PREFIX}/lib/timidity/patch && \
	unzip -o -q -L ${DISTDIR}/${TIINS}

.include <bsd.port.mk>
