# $NetBSD: Makefile,v 1.1 1998/06/23 16:42:24 agc Exp $

DISTNAME=	jdk115b1
PKGNAME=	jdk-1.1.5b1
CATEGORIES=	lang
MASTER_SITES=	http://www.fi.muni.cz/~dolecek/NetBSD/java/

MAINTAINER=	packages@netbsd.org

RESTRICTED=	'No redistribution of the Java(tm) Development Kit'
NO_PACKAGE=	${RESTRICTED}
MIRROR_DISTFILE=	no

ONLY_FOR_ARCHS=		i386

WRKSRC=		${WRKDIR}/jdk1.1.5

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	-${MKDIR} ${PREFIX}/java
	(cd ${WRKSRC}; tar cf - . | (cd ${PREFIX}/java ; tar xvf - ))

.include "../../mk/bsd.pkg.mk"
