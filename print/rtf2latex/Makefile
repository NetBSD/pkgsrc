# $NetBSD: Makefile,v 1.9 2003/07/17 22:52:38 grant Exp $
# FreeBSD Id: Makefile,v 1.7 1998/08/31 07:51:40 tg Exp
#

DISTNAME=	rtf2LaTeX.1.5
PKGNAME=	rtf2latex-1.5
WRKSRC=		${WRKDIR}/rtf2LaTeX
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dante.de/pub/tex/support/rtf2latex/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Filter that converts RTF (MS's Rich Text Format) into LaTeX

NO_CONFIGURE=	yes

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	XCFLAGS="${CPPFLAGS} -DSYSV" CC="${CC}"
.endif

.include "../../mk/bsd.pkg.mk"
