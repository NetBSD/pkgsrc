# $NetBSD: Makefile,v 1.12 2000/10/15 12:06:32 rh Exp $
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

DEPENDS+=	gtk+>=1.2.7:../../x11/gtk
DEPENDS+=	libmikmod>=3.1.7:../libmikmod
DEPENDS+=	libxml>=1.8.5:../../textproc/libxml

USE_LIBTOOL=	yes
USE_X11=	yes
USE_MESA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --without-gnome
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		XML_CONFIG="${LOCALBASE}/bin/xml-config"
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD)
CPPFLAGS+=	-I${WRKDIR}

.if (${MACHINE_ARCH} == i386)
post-patch:
.if (${OBJECT_FMT} == a.out)
	${CP} ${FILESDIR}/decode_i586_.s ${WRKSRC}/Input/mpg123/decode_i586.s
.endif
	cd ${WRKSRC}/Input/mpg123 && \
	${MV} decode_i586.s decode_i586.s.orig && \
	${SED} -e 's@^/@#/@g' <decode_i586.s.orig >decode_i586.s
.endif

pre-configure:
	${MKDIR} ${WRKDIR}/sys
	${LN} -fs /usr/include/soundcard.h ${WRKDIR}/sys/soundcard.h
.endif

.include "../../mk/bsd.pkg.mk"
