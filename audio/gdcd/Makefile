# $NetBSD: Makefile,v 1.8 2001/05/14 17:09:14 rh Exp $
#

DISTNAME=	gdcd-0.2.1
CATEGORIES=	audio
MASTER_SITES=	http://cdcd.undergrid.net/gdcd/source_archive/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://cdcd.undergrid.net/
COMMENT=	CD player for the X Window System using the GIMP Tool Kit (GTK)

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	libcdaudio>0.99.4:../../audio/libcdaudio

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

# for pth and libcdaudio
CPPFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
