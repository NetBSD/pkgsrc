# $NetBSD: Makefile,v 1.15 2003/11/11 09:17:53 abs Exp $
#

DISTNAME=	mserv-0.35
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.mserv.org/download/

MAINTAINER=	martin@NetBSD.org
HOMEPAGE=	http://www.mserv.org/
COMMENT=	Local centralised music server environment

DEPENDS+=	mpg123-[0-9]*:../mpg123

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	MY_LIBS="-lvorbisfile -lvorbis"
CONFIGURE_ARGS+=--datadir=${PREFIX}/share/mserv
USE_BUILDLINK2=	yes
REPLACE_PERL=	support/mservedit webclient/main.cgi webclient/margin.cgi webclient/mserv.cgi

LDFLAGS.SunOS+=	-lnsl -lsocket

post-configure:
	${MV} ${WRKSRC}/mserv/soundcard.h ${WRKSRC}/mserv/mservsoundcard.h

post-install:
	 ${INSTALL_SCRIPT} ${WRKSRC}/support/mservedit ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mserv
	${INSTALL_DATA} \
		${WRKSRC}/INSTALL \
		${WRKSRC}/LICENSE \
		${PREFIX}/share/doc/mserv
	${INSTALL_DATA_DIR} ${PREFIX}/share/mserv/webclient
	${INSTALL_DATA} \
		${WRKSRC}/webclient/* \
		${PREFIX}/share/mserv/webclient

.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
