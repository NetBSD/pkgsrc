# $NetBSD: Makefile,v 1.12 2001/07/19 16:22:41 tron Exp $

DISTNAME=	mm2.7
PKGNAME=	mm-2.7
CATEGORIES=	mail
MASTER_SITES=	ftp://thumper.bellcore.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	Implementation of MIME, the Multipurpose Internet Mail Extensions

CONFLICTS+=	elm>=2.5.5

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK_ONLY=	YES
USE_X11=		YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS=		-DSYSV
MAKE_ENV+=	CC="${CC}"
.endif

post-patch:
	${RM} -f ${WRKDIR}/mm2.7/src/bin/*.orig

.include "../../mk/bsd.pkg.mk"
