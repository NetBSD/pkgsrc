# $NetBSD: Makefile,v 1.4 2001/02/28 10:30:04 wiz Exp $
#

DISTNAME=	crossfire-0.95.8
PKGNAME=	crossfire-server-0.95.8
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/crossfire/
DISTFILES=	${CF_SRC} ${CF_MAPS}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://crossfire.real-time.com/
COMMENT=	X11 multi/single player game similar to gauntlet and nethack

EXTRACT_ONLY=	${CF_SRC}

CF_SRC=		crossfire-0.95.8.tar.bz2
CF_MAPS=	crossfire-0.95.8.maps.tar.bz2

USE_XPM=	yes
USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
SCRIPTS_ENV+=	${SCRIPTSDIR}
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}

post-install:
	cd ${LOCALBASE}/share/crossfire && \
	    ${GZCAT} ${DISTDIR}/${CF_MAPS} | ${GTAR} xmf -
	@${CHOWN} root:games ${LOCALBASE}/bin/crossfire
	@${CHMOD} 2755 ${LOCALBASE}/bin/crossfire
	@${CHOWN} -R root:games ${LOCALBASE}/share/crossfire
	@${CHOWN} -R root:games ${LOCALBASE}/var/crossfire
	@${CHMOD} -R g+w ${LOCALBASE}/var/crossfire

.include "../../mk/bsd.pkg.mk"
