# $NetBSD: Makefile,v 1.11 2004/04/25 03:19:39 snj Exp $

DISTNAME=	foomatic-gswrapper
PKGNAME=	foomatic-gswrapper-1.2
PKGREVISION=	1
CATEGORIES=	print
EXTRACT_SUFX=	# empty
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME_NOREV}/}

# The definitive location of the distfile is at www.linuxprinting.org,
# but this file has no revision number.
#
#MASTER_SITES+=	http://www.linuxprinting.org/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/gswrapper.html
COMMENT=	Foomatic Ghostscript Wrapper

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}

EXTRACT_CMD=		${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}/${DISTNAME}
USE_PERL5=		# defined
NO_BUILD=		# defined

REPLACE_PERL=	${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
