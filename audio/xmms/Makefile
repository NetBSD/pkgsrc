# $NetBSD: Makefile,v 1.5 2000/03/12 21:05:36 tron Exp $
# FreeBSD: ports/audio/xmms/Makefile,v 1.9 2000/02/11 01:46:12 cpiazza Exp

DISTNAME=	xmms-1.0.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.xmms.org/xmms/1.0/ \
		ftp://ftp.uk.xmms.org/xmms/1.0/ \
		ftp://ftp.us.xmms.org/xmms/1.0/ \
		ftp://ftp.ca.us.xmms.org/xmms/1.0/ \
		ftp://ftp.md.us.xmms.org/xmms/1.0/ \
		ftp://ftp.nl.xmms.org/xmms/1.0/ \
		ftp://ftp.de.xmms.org/xmms/1.0/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.xmms.org/

BROKEN=		\"gthread\" library needs to be fixed first.

DEPENDS+=	Mesa-*:../../graphics/Mesa
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	libmikmod>=3.1.7:../libmikmod
DEPENDS+=	libxml>=1.8.5:../../textproc/libxml
DEPENDS+=	pth>=1.3.2:../../devel/pth

USE_LIBTOOL=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --without-gnome
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		XML_CONFIG="${LOCALBASE}/bin/xml-config"

.include <../../mk/bsd.prefs.mk>

.if (${OPSYS} == NetBSD)
CPPFLAGS+=	-I${WRKDIR}

post-patch:
	cd ${WRKSRC}/Input/mpg123 && \
	${MV} decode_i586.s decode_i586.s.orig && \
	${SED} -e 's@^/@#/@g' <decode_i586.s.orig >decode_i586.s

pre-configure:
	${MKDIR} ${WRKDIR}/sys
	${LN} -fs /usr/include/soundcard.h ${WRKDIR}/sys/soundcard.h
.endif

.include "../../mk/bsd.pkg.mk"
