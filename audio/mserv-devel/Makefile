# $NetBSD: Makefile,v 1.5 2004/10/03 00:13:08 tv Exp $
#

DISTNAME=	mserv-0.39a
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mserv/}

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.mserv.org/
COMMENT=	Local centralised music server environment

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-engine-icecast
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/mserv
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

REPLACE_PERL=		support/mservedit webclient/main.cgi \
			webclient/margin.cgi webclient/mserv.cgi

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

.include "../../audio/libshout/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
