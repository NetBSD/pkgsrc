# $NetBSD: Makefile,v 1.23 2007/03/24 19:21:28 joerg Exp $

DISTNAME=	yorick-1.6.02
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/Yorick/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp-icf.llnl.gov/pub/Yorick/doc/index.html
COMMENT=	Numerical algebra system (similar to Matlab)

WRKSRC=		${WRKDIR}/yorick-1.6
BUILD_DIRS=	${WRKSRC} ${WRKSRC}/doc
INSTALL_DIRS=	${WRKSRC}
INSTALLATION_DIRS=	${PKGINFODIR} ${PKGMANDIR}/man1 share/doc share/emacs/site-lisp

USE_TOOLS+=	gmake makeinfo
INFO_FILES=	# PLIST

post-patch:
	for f in ${WRKSRC}/ysite.sh; do				\
	${SED} -e 's:@PREFIX@:${PREFIX}:g' $$f > $$f.tmp	\
	&& ${MV} $$f.tmp $$f;					\
	done

post-install:
	cd ${PREFIX}/bin; for f in yorick gist; do			\
		${LN} -sf ../lib/yorick/1.6/bin/$$f $$f;		\
	done
	cd ${WRKSRC}/doc; for f in yorick.info yorick.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${PREFIX}/${PKGMANDIR}/man1
	cd ${PREFIX}/share/doc && ${LN} -sf ../yorick/1.6/doc yorick
	${INSTALL_DATA} ${WRKSRC}/emacs/*.el ${PREFIX}/share/emacs/site-lisp

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
