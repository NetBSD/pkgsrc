# $NetBSD: Makefile,v 1.3 2004/12/14 18:47:09 minskim Exp $
#

DISTNAME=	gsmc-1.1
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.qsl.net/ik5nax/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.qsl.net/ik5nax/
COMMENT=	Smith charting program

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

.include "../../devel/pkgconfig/buildlink3.mk"
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
