# $NetBSD: Makefile,v 1.2 2000/03/07 23:03:12 tron Exp $
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

DEPENDS+=	Mesa-*:../../graphics/Mesa
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	libmikmod>=3.1.7:../libmikmod
DEPENDS+=	libxml>=1.8.5:../../textproc/libxml
DEPENDS+=	mit-pthreads-*:../../devel/mit-pthreads

USE_LIBTOOL=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --without-gnome
CC=		${LOCALBASE}/pthreads/bin/pgcc
LDFLAGS+=	-L${LOCALBASE}/lib

post-extract:
	@(cd ${WRKSRC}/Input/mpg123 && ${MV} decode_i586.s decode_i586.S && \
	 ${MV} getbits.s getbits.S && cd ${WRKSRC}/Visualization/blur_scope && \
	 ${MV} blur_8.s blur_8.S);
	@${PERL} -pi.bak -e 's:\.s :\.S :g' ${WRKSRC}/Input/mpg123/Makefile.in
	@${PERL} -pi.bak -e 's:blur_8.s:blur_8.S:g' \
	    ${WRKSRC}/Visualization/blur_scope/Makefile.in

.include "../../mk/bsd.pkg.mk"
