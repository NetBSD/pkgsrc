# $NetBSD: Makefile,v 1.56 2023/12/23 01:55:28 zafer Exp $
#

DISTNAME=	gsmc-1.1
PKGREVISION=	42
CATEGORIES=	cad
MASTER_SITES=	https://www.qsl.net/ik5nax/

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
