# $NetBSD: Makefile,v 1.25 2004/09/13 00:27:31 grant Exp $
#

DISTNAME=	mserv-0.35
PKGREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://www.mserv.org/download/

MAINTAINER=	martin@NetBSD.org
HOMEPAGE=	http://www.mserv.org/
COMMENT=	Local centralised music server environment

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/mserv
CONFIGURE_ENV+=		MY_LIBS="-lvorbisfile -lvorbis"
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

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

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
