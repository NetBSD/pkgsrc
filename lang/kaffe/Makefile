# New ports collection makefile for:    kaffe
# Version required:     0.9.2
# Date created:         20 February 1995
# Whom:                 Tim Wilkinson <tim@sarc.city.ac.uk>
#
# $NetBSD: Makefile,v 1.5 1998/02/02 08:59:27 hubertf Exp $
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
MAN1=		kaffe.1

post-install:
	${MKDIR} ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/ENVIRONMENT ${WRKSRC}/license.terms ${PREFIX}/share/kaffe
	${LDCONFIG} || ${TRUE}

.include <bsd.port.mk>
