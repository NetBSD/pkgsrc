# $NetBSD: Makefile,v 1.15 2002/09/23 21:01:43 jlam Exp $

DISTNAME=	mm2.7
PKGNAME=	metamail-2.7
CATEGORIES=	mail
MASTER_SITES=	ftp://thumper.bellcore.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	Implementation of MIME, the Multipurpose Internet Mail Extensions

CONFLICTS+=	elm>=2.5.5 mm-2.7

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK2=		YES
USE_X11=		YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS=		-DSYSV
.endif

post-patch:
	${RM} -f ${WRKDIR}/mm2.7/src/bin/*.orig

.include "../../mk/bsd.pkg.mk"
