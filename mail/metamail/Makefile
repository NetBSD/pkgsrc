# $NetBSD: Makefile,v 1.9 1999/09/03 08:19:11 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1996/11/21 11:27:26 asami Exp
#

DISTNAME=	mm2.7
PKGNAME=	mm-2.7
CATEGORIES=	mail
MASTER_SITES=	ftp://thumper.bellcore.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_X11=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS=		-DSYSV
MAKE_ENV+=	CFLAGS="${CFLAGS}" CC="${CC}"
.endif

post-patch:
	${RM} -f ${WRKDIR}/mm2.7/src/bin/*.orig

.include "../../mk/bsd.pkg.mk"
