# $NetBSD: Makefile,v 1.14 2010/10/03 07:32:42 obache Exp $
#

DISTNAME=	zircon-1.18.245
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://catless.ncl.ac.uk/Programs/Zircon/
COMMENT=	X11 interface to Internet Relay Chat
LICENSE=	original-bsd

NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	wish:run tclsh

do-install:
	@( cd ${WRKSRC} && ${TCLSH} installer/install.tcl -b ${PREFIX}/bin -l ${PREFIX}/share/zircon -w ${WISH} -g)
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/zircon
.for file in BUGS COPYRIGHT FAQ MANUAL MIRRORS README.ONS README.load README.look README.prefs TODO
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DESTDIR}${PREFIX}/share/doc/zircon
.endfor

.include "../../mk/bsd.pkg.mk"
