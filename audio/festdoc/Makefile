# $NetBSD: Makefile,v 1.3 1999/10/25 21:25:49 hubertf Exp $

DISTNAME=	festival-doc-1.4.0.1
WRKSRC=		${WRKDIR}/festdoc-1.4.0.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.0/
DISTFILES=	festdoc-1.4.0.1.tar.gz

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html

NO_BUILD=	yes

FDOC=		${PREFIX}/share/doc/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	find ${WRKSRC} -type d -print0 | xargs -0 chmod 755
	${RM} ${WRKSRC}/festival/src-manual/c3750.htm~
	${RM} ${WRKSRC}/speechtools/c16909.htm~


do-install:
	${INSTALL_DATA_DIR} ${FDOC}
	cd ${WRKSRC} && info=`find . -name '*.info*' -type f` && \
	  ${CP} $$info ${PREFIX}/info && \
	  ${CP} -r ${WRKSRC}/* ${FDOC} && \
	  cd ${FDOC} && \
	  ${RM} -f $$info

.include "../../mk/bsd.pkg.mk"
