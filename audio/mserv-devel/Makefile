# $NetBSD: Makefile,v 1.9 2009/12/17 19:58:19 abs Exp $
#

DISTNAME=	mserv-0.39a
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mserv/}

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.mserv.org/
COMMENT=	Local centralised music server environment

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-engine-icecast
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/mserv
USE_LIBTOOL=		yes

REPLACE_PERL=		support/mservedit webclient/main.cgi \
			webclient/margin.cgi webclient/mserv.cgi
USE_TOOLS+=		perl:run pkg-config

INSTALLATION_DIRS+= share/doc/mserv share/mserv/webclient
PKG_DESTDIR_SUPPORT= user-destdir

post-configure:
	${MV} ${WRKSRC}/mserv/soundcard.h ${WRKSRC}/mserv/mservsoundcard.h

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/support/mservedit ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} \
		${WRKSRC}/INSTALL \
		${WRKSRC}/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/mserv
	${INSTALL_DATA} \
		${WRKSRC}/webclient/* \
		${DESTDIR}${PREFIX}/share/mserv/webclient

.include "../../audio/libshout/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
