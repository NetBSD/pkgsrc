# $NetBSD: Makefile,v 1.48 2020/03/10 22:09:27 wiz Exp $
#

DISTNAME=	gsmc-1.1
PKGREVISION=	35
CATEGORIES=	cad
MASTER_SITES=	http://www.qsl.net/ik5nax/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.qsl.net/ik5nax/
COMMENT=	Smith charting program

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

LDFLAGS.SunOS+=		-lm
LDFLAGS.DragonFly=	-lm

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
