# $NetBSD: Makefile,v 1.1 1998/05/03 20:49:44 frueauf Exp $
# FreeBSD Id: Makefile,v 1.3 1998/04/30 02:38:03 obrien Exp
#

DISTNAME=       sane-0.72
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/

MAINTAINER=	packages@netbsd.org

LIB_DEPENDS=	gtk.1.:../../x11/gtk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11=	yes

MAN1=		scanimage.1 xscanimage.1 saned.1
MAN5=		sane-dll.5 sane-hp.5 sane-mustek.5 sane-net.5 sane-pnm.5 \
		sane-pint.5 sane-qcam.5 sane-umax.5 sane-scsi.5 sane-dmc.5 \
		sane-epson.5 sane-microtek.5

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
