# $NetBSD: Makefile,v 1.5 2001/02/17 17:51:54 wiz Exp $
# FreeBSD Id: Makefile,v 1.7 1998/08/31 07:51:40 tg Exp
#

DISTNAME=	rtf2LaTeX.1.5
PKGNAME=	rtf2latex-1.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dante.de/pub/tex/support/rtf2latex/

MAINTAINER=	packages@netbsd.org
COMMENT=	Filter that converts RTF (MS's Rich Text Format) into LaTeX

WRKSRC=		${WRKDIR}/rtf2LaTeX
NO_PATCH=	yes
NO_CONFIGURE=	yes

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	XCFLAGS="${CPPFLAGS} -DSYSV" CC="${CC}"
.endif

.include "../../mk/bsd.pkg.mk"
