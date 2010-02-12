# $NetBSD: Makefile,v 1.14 2010/02/12 00:08:35 joerg Exp $

DISTNAME=	rtf2LaTeX.1.5
PKGNAME=	rtf2latex-1.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dante.de/pub/tex/support/rtf2latex/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Filter that converts RTF (MS's Rich Text Format) into LaTeX

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/rtf2LaTeX
NO_CONFIGURE=	yes

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	XCFLAGS="${CPPFLAGS} -DSYSV" CC=${CC:Q}
.endif

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
