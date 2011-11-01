# $NetBSD: Makefile,v 1.19 2011/11/01 06:00:44 sbd Exp $
#

DISTNAME=	gsmc-1.1
PKGREVISION=	11
CATEGORIES=	cad
MASTER_SITES=	http://www.qsl.net/ik5nax/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qsl.net/ik5nax/
COMMENT=	Smith charting program

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

.include "../../x11/gtk2/buildlink3.mk"

# The following were just links in the distfile so
# replace them with working copies.
post-extract:
.for f in install-sh missing mkinstalldirs
	${RM} -f ${WRKSRC}/${f}
	${CP} ${FILESDIR}/${f} ${WRKSRC}
	${CHMOD} 755 ${WRKSRC}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
