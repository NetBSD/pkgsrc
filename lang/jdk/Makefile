# $NetBSD: Makefile,v 1.6 1999/02/05 16:33:34 frueauf Exp $

DISTNAME=		jdk1.1.6
PKGNAME=		jdk-1.1.6
WRKSRC=			${WRKDIR}/jdk1.1.6
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/misc/java/i386/1.1.6/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.quick.com.au/java/

RESTRICTED=		'No redistribution of the Java(tm) Development Kit'
NO_PACKAGE=		${RESTRICTED}
MIRROR_DISTFILE=	no

ONLY_FOR_ARCHS=		i386

NO_CONFIGURE=		yes
NO_BUILD=		yes

CONFLICTS=		jdk-*

do-install:
	${RM} ${WRKSRC}/README.NetBSD.orig
	-${MKDIR} ${PREFIX}/java
	(cd ${WRKSRC}; tar cf - . | (cd ${PREFIX}/java ; tar xvf - ))

.include "../../mk/bsd.pkg.mk"
