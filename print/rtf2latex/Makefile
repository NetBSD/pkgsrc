# $NetBSD: Makefile,v 1.11 2005/03/24 21:13:00 wiz Exp $

DISTNAME=	rtf2LaTeX.1.5
PKGNAME=	rtf2latex-1.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dante.de/pub/tex/support/rtf2latex/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Filter that converts RTF (MS's Rich Text Format) into LaTeX

WRKSRC=		${WRKDIR}/rtf2LaTeX
NO_CONFIGURE=	yes

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	XCFLAGS="${CPPFLAGS} -DSYSV" CC="${CC}"
.endif

.include "../../mk/bsd.pkg.mk"
