# $NetBSD: Makefile,v 1.11 2001/06/22 16:16:06 jlam Exp $
# FreeBSD Id: Makefile,v 1.8 1996/11/21 11:27:26 asami Exp
#

DISTNAME=	mm2.7
PKGNAME=	mm-2.7
CATEGORIES=	mail
MASTER_SITES=	ftp://thumper.bellcore.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	Implementation of MIME, the Multipurpose Internet Mail Extensions

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK_ONLY=	yes
USE_X11=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS=		-DSYSV
MAKE_ENV+=	CC="${CC}"
.endif

post-patch:
	${RM} -f ${WRKDIR}/mm2.7/src/bin/*.orig

.include "../../mk/bsd.pkg.mk"
