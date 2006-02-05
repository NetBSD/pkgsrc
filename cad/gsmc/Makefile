# $NetBSD: Makefile,v 1.9 2006/02/05 23:08:21 joerg Exp $
#

DISTNAME=	gsmc-1.1
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	http://www.qsl.net/ik5nax/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.qsl.net/ik5nax/
COMMENT=	Smith charting program

PKG_INSTALLATION_TYPES= overwrite pkgviews

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
