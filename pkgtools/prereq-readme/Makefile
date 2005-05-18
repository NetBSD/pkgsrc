# $NetBSD: Makefile,v 1.1.1.1 2005/05/18 04:48:24 dmcmahill Exp $
#

DISTNAME=	prereq-readme-20050518
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	Tools required for pkgsrc README.html generation

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	# defined
NO_CONFIGURE=  	# defined
NO_BUILD=   	# defined
NO_INSTALL=   	# defined
NO_PACKAGE=   	# defined

# list all the tools we use
PKGSRC_USE_TOOLS+=	awk
PKGSRC_USE_TOOLS+=	cmp
PKGSRC_USE_TOOLS+=	echo
PKGSRC_USE_TOOLS+=	expr
PKGSRC_USE_TOOLS+=	fgrep
PKGSRC_USE_TOOLS+=	grep
PKGSRC_USE_TOOLS+=	sed
PKGSRC_USE_TOOLS+=	setenv
PKGSRC_USE_TOOLS+=	sort

.include "../../mk/bsd.pkg.mk"
