# $NetBSD: Makefile,v 1.19 2006/03/31 23:56:28 jlam Exp $

DISTNAME=	yorick-1.6.02
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=   ftp://ftp-icf.llnl.gov/pub/Yorick/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp-icf.llnl.gov/pub/Yorick/doc/index.html
COMMENT=	Numerical algebra system (similar to Matlab)

WRKSRC=		${WRKDIR}/yorick-1.6
BUILD_DIRS=	${WRKSRC} ${WRKSRC}/doc
INSTALL_DIRS=	${WRKSRC}

USE_TOOLS+=	gmake makeinfo
INFO_FILES=	# PLIST

.include "../../mk/x11.buildlink3.mk"

post-patch:
	for f in ${WRKSRC}/ysite.sh; do				\
	${SED} -e 's:@PREFIX@:${PREFIX}:g' $$f > $$f.tmp	\
	&& ${MV} $$f.tmp $$f;					\
	done

post-install:
	cd ${PREFIX}/bin; for f in yorick gist; do			\
		${LN} -sf ../lib/yorick/1.6/bin/$$f $$f;		\
	done
	cd ${WRKSRC}; for f in yorick.info yorick.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${PREFIX}/${PKGMANDIR}/man1
	cd ${PREFIX}/share/doc && ${LN} -sf ../yorick/1.6/doc yorick
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/emacs/*.el ${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
