# $NetBSD: Makefile,v 1.19 2004/01/23 06:37:00 grant Exp $
#

DISTNAME=	mserv-0.35
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://www.mserv.org/download/

MAINTAINER=	martin@NetBSD.org
HOMEPAGE=	http://www.mserv.org/
COMMENT=	Local centralised music server environment

DEPENDS+=	mpg123-[0-9]*:../mpg123

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/mserv
CONFIGURE_ENV+=		MY_LIBS="-lvorbisfile -lvorbis"
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

REPLACE_PERL=		support/mservedit webclient/main.cgi \
			webclient/margin.cgi webclient/mserv.cgi

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
