# $NetBSD: Makefile,v 1.4 2003/04/29 22:41:44 jtb Exp $

DISTNAME=	yorick-1.5.12
CATEGORIES=	math
MASTER_SITES=   ftp://ftp-icf.llnl.gov/pub/Yorick/
EXTRACT_SUFX=	.tgz

MAINTAINER=	refling@comet.lbl.gov
HOMEPAGE=	ftp://ftp-icf.llnl.gov/pub/Yorick/doc/index.html
COMMENT=	Numerical algebra system (similar to Matlab)

WRKSRC=		${WRKDIR}/yorick-1.5

USE_X11=        yes

INFO_FILES=	yorick.info

post-patch:
	for f in ${WRKSRC}/ysite.sh; do				\
	${SED} -e 's:@PREFIX@:${PREFIX}:g' $$f > $$f.tmp	\
	&& ${MV} $$f.tmp $$f;					\
	done

post-install:
	for f in yorick gist; do \
	cd ${PREFIX}/bin && ${LN} -sf ../lib/yorick/1.5/bin/$$f $$f; \
	done
	cd ${WRKSRC}/doc && ${MAKE} all
	${INSTALL_DATA} ${WRKSRC}/doc/yorick.info* ${PREFIX}/info
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${PREFIX}/man/man1
	cd ${PREFIX}/share/doc && ${LN} -sf ../yorick/1.5/doc yorick
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/emacs/*.el ${PREFIX}/share/emacs/site-lisp

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
