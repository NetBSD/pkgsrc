# $NetBSD: Makefile,v 1.12 2002/02/18 15:14:01 seb Exp $

DISTNAME=	festdoc-1.4.0.1
PKGNAME=	festival-doc-1.4.0.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.1/ \
		http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html
COMMENT=	Festival documentation, in (tex)info, html, dvi and ps formats

NO_BUILD=	yes

FDOC=		${PREFIX}/share/doc/festival

INFO_FILES=	festival.info

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${RM} ${WRKSRC}/festival/src-manual/c3750.htm~
	${RM} ${WRKSRC}/speechtools/c16909.htm~
	${RMDIR} ${WRKSRC}/festival/src-manual/images_gen

do-install:
	${INSTALL_DATA_DIR} ${FDOC}
	cd ${WRKSRC} && info=`${FIND} . -name '*.info*' -type f` && \
		${CP} $$info ${PREFIX}/info && \
		${CP} -r ${WRKSRC}/* ${FDOC} && \
		cd ${FDOC} && \
		${RM} -f $$info && \
		${RMDIR} festival/info
	${RM} ${PREFIX}/info/festival.info.orig

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
