# $NetBSD: Makefile,v 1.16 2016/02/25 17:52:45 jperkin Exp $

DISTNAME=	rtf2LaTeX.1.5
PKGNAME=	rtf2latex-1.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dante.de/pub/tex/support/rtf2latex/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Filter that converts RTF (MS's Rich Text Format) into LaTeX

WRKSRC=		${WRKDIR}/rtf2LaTeX
NO_CONFIGURE=	yes

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

MAKE_ENV.SunOS+=	XCFLAGS="${CPPFLAGS} -DSYSV" CC=${CC:Q}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
