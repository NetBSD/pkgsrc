# $NetBSD: Makefile,v 1.12 2003/05/02 11:55:49 wiz Exp $
#

DISTNAME=	gperiodic-1.2.6
PKGREVISION=	1
WRKSRC=		${WRKDIR}/gperiodic
CATEGORIES=	misc x11
MASTER_SITES=	ftp://ftp.seul.org/pub/gperiodic/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://gperiodic.seul.org/
COMMENT=	Displays a periodic table of the elements

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK2=		# defined
USE_PKGLOCALEDIR=	# defined
USE_X11BASE=		# defined
USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined

pre-configure:
.for f in config.cache config.h config.log config.status
	${RM} -f ${WRKSRC}/$f
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/gperiodic.1 ${PREFIX}/man/man1/

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
