# $NetBSD: Makefile,v 1.8 1998/07/15 11:48:29 agc Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/08 09:37:16 obrien Exp
#

DISTNAME=	kaffe-0.9.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.kaffe.org/pub/kaffe/ \
		ftp://ftp.cs.columbia.edu/pub/kaffe/ \
		http://www.webcity.co.jp/info/andoh/java/kaffe/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}.tgz kaffe-0.9.2-package-javasoft.com.tgz \

MAINTAINER=	xaa@stack.nl

RESTRICTED=	'No redistribution of the Java(tm) Development Kit'
NO_PACKAGE=	${RESTRICTED}
MIRROR_DISTFILE=	no
ONLY_FOR_ARCHS=		i386

GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/ENVIRONMENT ${WRKSRC}/license.terms ${PREFIX}/share/kaffe

.include "../../mk/bsd.pkg.mk"
