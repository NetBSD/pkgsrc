# $NetBSD: Makefile,v 1.6 2001/08/01 16:26:56 wiz Exp $
#

DISTNAME=	crossfire-1.0.0
PKGNAME=	crossfire-server-1.0.0
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.scruz.net/users/mwedel/public/
DISTFILES=	${CF_SRC} ${CF_MAPS}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://crossfire.real-time.com/
COMMENT=	X11 multi/single player game similar to gauntlet and nethack

DEPENDS+=	png>=1.0.11:../../graphics/png

EXTRACT_ONLY=	${CF_SRC}

CF_SRC=		crossfire-1.0.0.tar.bz2
CF_MAPS=	crossfire-1.0.0-maps.tar.bz2

USE_XAW=	yes
USE_XPM=	yes
USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
SCRIPTS_ENV+=	${SCRIPTSDIR}
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}
CONFIGURE_ARGS+=	--with-includes=-I${LOCALBASE}/include

post-install:
	cd ${LOCALBASE}/share/crossfire && \
	    ${GZCAT} ${DISTDIR}/${CF_MAPS} | ${GTAR} xmf -
	@${CHOWN} root:games ${LOCALBASE}/bin/crossfire
	@${CHMOD} 2755 ${LOCALBASE}/bin/crossfire
	@${CHOWN} -R root:games ${LOCALBASE}/share/crossfire
	@${CHOWN} -R root:games ${LOCALBASE}/var/crossfire
	@${CHMOD} -R g+w ${LOCALBASE}/var/crossfire

.include "../../mk/bsd.pkg.mk"
