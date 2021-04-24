# $NetBSD: Makefile,v 1.17 2021/04/24 10:46:24 wiz Exp $

DISTNAME=	rtf2LaTeX.1.5
PKGNAME=	rtf2latex-1.5
CATEGORIES=	print
MASTER_SITES=	https://www.ctan.org/tex-archive/support/rtf2latex/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Filter that converts RTF (MS's Rich Text Format) into LaTeX

WRKSRC=		${WRKDIR}/rtf2LaTeX
NO_CONFIGURE=	yes

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

MAKE_ENV.SunOS+=	XCFLAGS="${CPPFLAGS} -DSYSV" CC=${CC:Q}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
