# $NetBSD: Makefile,v 1.32 2020/03/20 11:58:01 nia Exp $

DISTNAME=	yorick-1.6.02
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/johans/yorick/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yorick.sourceforge.net/
COMMENT=	Numerical algebra system (similar to Matlab)

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/yorick-1.6
BUILD_DIRS=		${WRKSRC} doc
INSTALL_DIRS=		${WRKSRC}
INSTALLATION_DIRS=	bin ${PKGINFODIR} ${PKGMANDIR}/man1 share/doc share/emacs/site-lisp
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

USE_TOOLS+=	gmake makeinfo
INFO_FILES=	yes

post-patch:
	for f in ${WRKSRC}/ysite.sh; do				\
	${SED} -e 's:@PREFIX@:${PREFIX}:g' $$f > $$f.tmp	\
	&& ${MV} $$f.tmp $$f;					\
	done

post-install:
	${LN} -sf ../lib/yorick/1.6/bin/yorick ${DESTDIR}${PREFIX}/bin/yorick
	${LN} -sf ../lib/yorick/1.6/bin/gist ${DESTDIR}${PREFIX}/bin/gist
	cd ${WRKSRC}/doc; for f in yorick.info yorick.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};		\
	done
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${LN} -sf ../yorick/1.6/doc ${DESTDIR}${PREFIX}/share/doc/yorick
	${INSTALL_DATA} ${WRKSRC}/emacs/*.el ${DESTDIR}${PREFIX}/share/emacs/site-lisp

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
