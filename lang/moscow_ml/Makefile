# New ports collection makefile for:    moscow-ml
# Version required:     1.42
# Date created:         17 February 1998
# Whom:                 lamj@stat.cmu.edu
#
# $NetBSD: Makefile,v 1.1 1998/02/17 10:18:36 agc Exp $
#

DISTNAME=       mos14src
PKGNAME=        moscow_ml-1.42
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/mosml/

MAINTAINER=	lamj@stat.cmu.edu

USE_PERL5=	yes
WRKSRC=		${WRKDIR}/mosml/src
ALL_TARGET=	world

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/moscow_ml
	${MKDIR} ${PREFIX}/share/examples/moscow_ml
.for file in bugs manual.dvi mosmlref.dvi releases.txt
	${INSTALL_DATA} ${WRKDIR}/mosml/doc/${file} ${PREFIX}/share/doc/moscow_ml
.endfor
	${CP} -R ${WRKDIR}/mosml/examples/* ${PREFIX}/share/examples/moscow_ml
.endif

.include <bsd.port.mk>
